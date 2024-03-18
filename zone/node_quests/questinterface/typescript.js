const fs = require("fs");
const path = require("path");

const { classes, enums, structs } = require("./myenv/header_output.json");

const getTypeData = (arg) => {
  arg = arg.replace(/\w+::/, "");
  switch (arg) {
    case "char*":
      return {
        wrap_type: "std::vector<char>*",
        js_type: "CharVector",
        parameter: (name) => `${name}->data()`,
        fromVal: {
          isType: (name) =>
            `${name}.instanceof (val::module_property("CharVector"))`,
          parameter: (name) => `${name}.as<std::vector<char>*>()->data()`,
        },
        return: (expr) => `val::take_ownership(CToJString(${expr}))`,
      };
    case "std::string":
    case "const char*":
      return {
        wrap_type: "const std::string&",
        js_type: "string",
        parameter: (name) => `${name}.c_str()`,
        fromVal: {
          isType: (name) => `${name}.isString()`,
          parameter: (name) => `${name}.as<std::string>().c_str()`,
        },
        return: (expr) => `val::take_ownership(CToJString(${expr}))`,
      };
    case "const char**":
      return {
        js_type: "Array<String>",
        wrap_type: "const val&",
        variant: true,
        fromVal: {
          isType: (name) => `${name}.isArray() && ${name}[0].isString()`,
          parameter: (name) => `${name}_param.data()`,
          extract: (name) => [
            `auto ${name}_temp = vecFromJSArray<std::string>(${name});`,
            `std::vector<const char*> ${name}_param;`,
            `${name}_param.reserve(${name}_temp.size());`,
            `for (auto const& str : ${name}_temp) {`,
            `  ${name}_param.push_back(str.c_str());`,
            `}`,
          ],
        },
      };
    case "const double*":
      return {
        js_type: "Float64Array",
        wrap_type: "const val&",
        variant: true,
        fromVal: {
          isType: (name) => `${name}.isArray() && ${name}[0].isNumber()`,
          parameter: (name) =>
            `convertJSArrayToNumberVector<double>(${name}).data()`,
        },
      };
    case "const int*":
      return {
        js_type: "Int32Array",
        wrap_type: "const val&",
        variant: true,
        fromVal: {
          isType: (name) => `${name}.isArray() && ${name}[0].isNumber()`,
          parameter: (name) =>
            `convertJSArrayToNumberVector<int>(${name}).data()`,
        },
      };
    case "double*":
    case "int*":
    case "unsigned char*": {
      const valueType = arg.replace("*", "");
      let js_type = {
        ["double*"]: "DoubleVector",
        ["int*"]: "IntVector",
        ["unsigned char*"]: "ByteVector",
      }[arg];
      return {
        wrap_type: `std::vector<${valueType}>*`,
        js_type,
        parameter: (name) => `${name}->data()`,
        fromVal: {
          isType: (name) =>
            `${name}.instanceof (val::module_property("${js_type}"))`,
          parameter: (name) =>
            `${name}.as<std::vector<${valueType}>*>()->data()`,
        },
      };
    }
    case "bool":
      return {
        js_type: "boolean",
        wrap_type: arg,
        parameter: (name) => name,
        basic: true,
        fromVal: {
          isType: (name) => `${name}.typeOf().as<std::string>() == "boolean"`,
          parameter: (name) => `${name}.as<bool>()`,
        },
      };
    case "unsigned char":
    case "signed char":
    case "int":
    case "char":
    case "double":
      return {
        js_type: "number",
        wrap_type: arg,
        parameter: (name) => name,
        basic: true,
        fromVal: {
          isType: (name) => `${name}.isNumber()`,
          parameter: (name) => `${name}.as<${arg}>()`,
        },
      };
    case "char**":
      throw new Error("String output buffer not supported");
    case "void":
      return { wrap_type: arg, noreturn: true, basic: true };
    case "int (*)()":
      // could regex this but these should be rare so just one off it
      return {
        js_type: "function",
        wrap_type: "val",
        variant: true,
        fromVal: {
          isType: (name) =>
            `!${name}.isNull() && ${name}.typeOf().as<std::string>() == "function"`,
          parameter: (name) => `${name}`,
        },
      };
    default:
      if (
        arg.includes("int") ||
        arg.includes("long") ||
        arg.includes("short")
      ) {
        return {
          js_type: "number",
          wrap_type: arg,
          parameter: (name) => name,
          basic: true,
          fromVal: {
            isType: (name) => `${name}.isNumber()`,
            parameter: (name) => `${name}.as<${arg}>()`,
          },
        };
      }
      break;
  }
  const isConst = arg.startsWith("const");
  let wrap_type = isConst ? `const ${arg.replace("const ", "")}` : `${arg}`;

  const pointer = arg.includes("*");
  if (wrap_type.endsWith("&&")) {
    // rvalue specialization
    wrap_type = wrap_type.replace("&&", "*");
    return {
      wrap_type,
      parameter: (name) => `std::move(*(${name}))`,
      pointer,
      basic: true,
      fromVal: {
        isType: (name) =>
          `${name}.instanceof (val::module_property("${wrap_type
            .replace("NodeQuest::", "")
            .replace("*", "")
            .replace("const", "")
            .trim()}"))`,
        parameter: (name) =>
          `std::move(*(${name}.as<${wrap_type}>(allow_raw_pointers())))`,
      },
    };
  }
  const enumType = enums[wrap_type.split("::").pop().replace("*", "")];
  if (enumType?.asFlag) {
    return {
      wrap_type: "int",
      parameter: (name) => `(${wrap_type})${name}`,
      pointer: false,
      basic: false,
      fromVal: {
        isType: (name) => `${name}.isNumber()`,
        parameter: (name) => `static_cast<${wrap_type}>(${name}.as<int>())`,
      },
    };
  }
  let parameter = (name) => name;
  if (enumType && pointer) {
    if (isConst) {
      throw new Error(`not expecting const enum*  ${type}`);
    }
    wrap_type = arg.replace("*", "Ptr*");
    parameter = (name) => `${name}->data()`;
  }
  return {
    wrap_type,
    parameter,
    pointer,
    basic: !pointer,
    fromVal: {
      isType: (name) =>
        `${name}.instanceof (val::module_property("${wrap_type
          .replace("NodeQuest::", "")
          .replace("*", "")
          .replace("const", "")
          .trim()}"))`,
      parameter: (name) => `${name}.as<${wrap_type}>()`,
    },
  };
};
const indent = (lines, spaces = "") =>
  Array.isArray(lines)
    ? `${lines.map((x) => indent(x, spaces + "  ")).join(`\n`)}`
    : `${spaces}${lines}`;

const getTsTypeData = (
  type,
  { isConst = false, isSmart = false, isReturn = false } = {}
) => {
  type = type.replace(/\w+::/, "");
  if (type.startsWith("char") && isConst) {
    return getTypeData(`const ${type}`).js_type;
  }
  let tsType =
    getTypeData(type).js_type ??
    type.replace(/[*&]/g, "").replace("const ", "");
  if (tsType.includes("std::string") || tsType === "char") {
    tsType = "string";
  }
  tsType = tsType.replace(/\w+::/, "");
  if (isSmart) {
    return `SmartPtr<${tsType}> & ${tsType}`;
  }
  if (Object.keys(enums).includes(tsType) && type.includes("*")) {
    return `${tsType}Ptr`;
  }
  return tsType;
};

const typescriptTemplate = `/** NodeQuest API definitions **/

export default NodeQuest

export declare module NodeQuest {
  class RegisteredPointer {
    delete(): void;
  }
  class Owned<T> extends RegisteredPointer {}
  class NodeQuestVector<T, U> extends RegisteredPointer {
    /**
     * Always call delete on registered pointers when finished.
     */
    constructor(size?: number);
    get(index: number): T;
    set(index: number, el :T): boolean;
    size(): number;
    push_back(el: T): void;
    resize(sise: number): void;
    toJS(): U;
  }

${[
  ["ByteVector", "any", "Uint8Array"],
  ["CharVector", "any", "string"],
  ["IntVector", "number", "Int32Array"],
  ["DoubleVector", "number", "Float64Array"],
]
  .map(([val, type, returnType]) =>
    indent(
      `class ${val} extends NodeQuestVector<${type}, ${returnType}> {}`,
      "  "
    )
  )
  .join("\r\n")}

  type EnumInstance<T> = { get values(): { [V in T[keyof T]]: { get value(): V } } } & { [P in keyof T]: { get value(): T[P] } }
  export class EnumPtr<T> extends RegisteredPointer {
    /**
     * Always call delete on registered pointers when finished.
     */
    constructor(param?: T);
    get() : { get value(): T[keyof T] };
  }

  export interface SmartPtr<T> extends RegisteredPointer {
    get() : T;
  }

  /** Enums and Enum Class Wrappers **/${enums
    .reduce((acc, { name: enumName, values }) => {
      acc.push(`
  const ${enumName}Enum = {
${values
  .map(({ name, value }) => indent(`${name}: ${value}`, "    "))
  .join(",\r\n")}
  } as const;`);
      acc.push(
        `  export const ${enumName}: EnumInstance<typeof ${enumName}Enum>;`
      );
      acc.push(
        `  export class ${enumName}Ptr extends EnumPtr<typeof ${enumName}Enum> {}`
      );
      return acc;
    }, [])
    .join("\r\n")}

  /** Structs **/${structs
    .map(({ name, attributes }) => {
      name = name.replace(/\w+::/, "");
      return `
  export interface ${name} {
${attributes
  .map(({ name, type }) => indent(`${name}: ${getTsTypeData(type)}`, "    "))
  .join(",\r\n")}
  }`;
    })
    .join("\r\n")}

  /** Class Interfaces **/${classes
    .map(({ name, methods, inherits, attributes }) => {
      name = name.replace(/\w+::/, "");
      const constructorLines = methods.filter((a) => a.name === name).length
        ? `{
  ${methods
    .filter((a) => a.name === name)
    .map(({ parameters }) => {
      const argMap = parameters
        .map((a, i) => `${a.name}: ${getTsTypeData(a.type)}`)
        .join(", ");
      return indent(`constructor(${argMap});`, "  ");
    })
    .join(";\r\n")}`
        : `{`;
      return `
  export class ${name}${
        inherits.length ? ` extends ${inherits.join(", ")}` : ""
      } ${constructorLines}
  ${attributes
    .map(
      ({ name, type }) =>
        indent(`${name} : ${getTsTypeData(type, {
          isConst: type.startsWith("const"),
          isReturn: true,
        })};`, "    ")
    )
    .join("\r\n")}
${methods
  .filter((a) => a.name !== name)
  .reduce((acc, { name, returnType, parameters }) => {
    const argMap = parameters
      .map(({ name, type }, i) => {
        const arg = getTsTypeData(type, { isConst: type.startsWith("const") });
        if (name === "in" || name === "with") {
          name = "";
        }
        return `${name || `arg${i}`}: ${arg}`;
      })
      .join(", ");
    acc.push(
      indent(
        `${name}(${argMap}): ${getTsTypeData(returnType, {
          isConst: returnType.startsWith("const"),
          isReturn: true,
        })}`,
        "    "
      )
    );

    return acc;
  }, [])
  .join(";\r\n")}
  }`;
    })
    .join("\r\n")}
}
`;

fs.writeFileSync("./nodequest.d.ts", typescriptTemplate, "utf-8");
