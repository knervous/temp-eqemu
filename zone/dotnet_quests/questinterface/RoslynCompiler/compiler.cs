using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Emit;
using System.Reflection;
class Program
{
    static void Main(string[] args)
    {
        var zone = args[0];

        string assemblyLocation = Assembly.GetExecutingAssembly().Location;
        var assemblyDirectory = Path.GetDirectoryName(assemblyLocation);

        string rootPath = $"{assemblyDirectory}/dotnet_quests/{zone}";
        string searchPattern = "*.csx";

        var directories = Directory.GetDirectories(rootPath, "*", SearchOption.AllDirectories);
        var allMatchingFiles = new List<string>();

        allMatchingFiles.AddRange(Directory.GetFiles(rootPath, searchPattern, SearchOption.AllDirectories));

        foreach (var directory in directories)
        {
            allMatchingFiles.AddRange(Directory.GetFiles(directory, searchPattern, SearchOption.AllDirectories));
        }

        var totalCode = "";
        List<string> allUsings = new List<string>();
        foreach (var file in allMatchingFiles)
        {
            var fileName = Path.GetFileNameWithoutExtension(file);
            var text = File.ReadAllText(file);
            text = text.Replace("#r \"../../DotNetTypes.dll\"", "");
            text = text.Replace("#r \"../../RoslynBridge.dll\"", "");

            var lines = text.Split(new[] { "\r\n", "\n" }, StringSplitOptions.None);
            var usingLines = lines.Where(line => line.StartsWith("using ")).OrderBy(line => line).ToList();
            foreach(var usingLine in usingLines) {
                if (!allUsings.Contains(usingLine.Trim())) {
                    allUsings.Add(usingLine.Trim());
                }
            }
            var otherLines = lines.Where(line => !line.StartsWith("using ")).ToList();

            string sortedOtherLines = string.Join("\n", otherLines);

            text = @$"
                public class {fileName} {{
                    {sortedOtherLines}
                }}
            ";

            totalCode += text;
        }

        totalCode = $@"
            {string.Join("\n", allUsings)}
            {totalCode}
        ";

        var syntaxTree = CSharpSyntaxTree.ParseText(totalCode);
        string systemRuntimePath = typeof(object).GetTypeInfo().Assembly.Location;

        var references = new List<MetadataReference>
        {
            MetadataReference.CreateFromFile(typeof(object).Assembly.Location),
            MetadataReference.CreateFromFile("DotNetTypes.dll"),
            MetadataReference.CreateFromFile(systemRuntimePath)
        };

        // If targeting .NET Core or .NET 5/6/7, you might also need to add references like this:
        var coreDir = Path.GetDirectoryName(typeof(object).GetTypeInfo().Assembly.Location);
        foreach(var usingLine in allUsings) {
            var dllPath = Path.Combine(coreDir, $"{usingLine}.dll").Replace("using ", "").Replace(";", "");
            if (File.Exists(dllPath)) {
                references.Add(MetadataReference.CreateFromFile(dllPath));
            }
        }
        references.Add(MetadataReference.CreateFromFile(Path.Combine(coreDir, "System.Runtime.dll")));
        references.Add(MetadataReference.CreateFromFile(Path.Combine(coreDir, "System.Console.dll")));

        var compilation = CSharpCompilation.Create(
            assemblyName: zone,
            syntaxTrees: new[] { syntaxTree },
            references: references,
            options: new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));

        EmitOptions emitOptions = new EmitOptions(debugInformationFormat: DebugInformationFormat.PortablePdb);
        using (var ms = new MemoryStream())
        {
            EmitResult result = compilation.Emit(ms, options: emitOptions);

            if (!result.Success)
            {
                // Handle compilation errors (e.g., print them out)
                foreach (var diagnostic in result.Diagnostics)
                {
                    Console.Error.WriteLine(diagnostic.ToString());
                }

                Environment.Exit(1);
            }

            ms.Seek(0, SeekOrigin.Begin);
            // Convert the MemoryStream's buffer to a Base64 string
            string base64String = Convert.ToBase64String(ms.ToArray());

            // Write the Base64 string to stdout
            Console.WriteLine(base64String);
        }
    }
}