import CppHeaderParser
import json
import os

# List your header files here
header_files = [
    "../../../../common/ruletypes.h",
    "../../../../common/expedition_lockout_timer.h",
    "../../../common.h",
    "../../../entity.h",
    "../../../mob.h",
    "../../../npc.h",
    "../../../encounter.h",
    "../../../beacon.h",
    "../../../zone.h",
    "../../../client.h",
    "../../../corpse.h",
    "../../../doors.h",
    "../../../groups.h",
    "../../../object.h",
    "../../../raids.h",
    "../../../trap.h"
]
script_dir = os.path.dirname(os.path.abspath(__file__))
header_paths = [os.path.join(script_dir, header) for header in header_files]


concatenated_header_path = os.path.join(script_dir, "merged_header.h")
with open(concatenated_header_path, 'w') as outfile:
    for fname in header_paths:
        with open(fname) as infile:
            for line in infile:
                outfile.write(line)
            # Optionally add a new line after each file to ensure separation
            outfile.write('\n')

# The accumulated data
data = {"classes": [], "enums": [], "static_functions": [], "structs": []}

try:
    cpp_header = CppHeaderParser.CppHeader(concatenated_header_path)

    # Extract classes and structs
    for class_name, class_info in cpp_header.classes.items():
        base_classes = []
        
        # Check if the class has any inheritance information
        if 'inherits' in class_info:
            # Iterate over each inheritance entry
            for inheritance_info in class_info['inherits']:
                # Each inheritance_info is expected to be a dict with a 'class' key
                base_class_name = inheritance_info['class']  # Extract the base class name
                base_classes.append(base_class_name)  # Add it to the list of base classes
        
        class_dict = {
            "name": class_name,
            "type": "class" if class_info["declaration_method"] == "class" else "struct",
            "methods": [],
            "inherits": base_classes,  # Include base classes here
            # Only include attribute names or simplified representations
            "attributes": [{"name": attr["name"], "type": attr["type"]} for attr in class_info['properties']['public']]

        }
        for access in ["public", "protected", "private"]:
            for method in class_info["methods"][access]:
                # Check for 'modifiers' key and handle the case where it's missing
                modifiers = method.get("modifiers", [])
                simplified_parameters = [{"type": p["type"], "name": p["name"]} for p in method["parameters"]]

                class_dict["methods"].append({
                    "name": method["name"],
                    "returnType": method["rtnType"],
                    "parameters": simplified_parameters,
                    "access": access
                })
        if class_dict["type"] == "class":
            data["classes"].append(class_dict)
        else:
            data["structs"].append(class_dict)
    
    # Extract enums
    for enum in cpp_header.enums:
        if "name" not in enum:
            continue
        data["enums"].append({
            "name": enum["name"],
            "values": enum["values"]
        })

    # Optionally, extract global static functions similarly to class methods
    
except CppHeaderParser.CppParseError as e:
    print(f"Error parsing {header_file}: {e}")

# Convert data to JSON
json_data = json.dumps(data, indent=4)

# Save to file
with open('header_output.json', 'w') as json_file:
    json_file.write(json_data)

print("JSON data written to header_output.json")
