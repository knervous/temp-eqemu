{
    "targets": [
        {
            "target_name": "eqemu-quests",
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": "2",
                    "AdditionalOptions": ['/std:c++17']
                }
            },
            "conditions": [
                ["OS=='win'",
                 {
                     "msbuild_toolset": "v142",
                     "link_settings": {
                         "libraries": ["../../module/MtbCore.lib"]
                     }
                 }
                 ],
                ["OS=='mac'",
                    {
                        "xcode_settings": {
                            "GCC_ENABLE_CPP_RTTI": "YES",
                            "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                            "OTHER_CFLAGS": ["-std=c++17"],
                        },
                        "link_settings": {
                            "libraries": ["../../module/MtbCore", "-Wl,-rpath,@loader_path"]
                        }
                    }
                 ],
                ["OS=='linux'",
                    {
                        "cflags+": ["-frtti", "-fexceptions", "-std=c++17"],
                        "cflags_c+": ["-frtti", "-fexceptions", "-std=c++17"],
                        "cflags_cc+": ["-frtti", "-fexceptions", "-std=c++17"],
                        "link_settings": {
                            "libraries": ["../../module/libMtbCore.so", "-Wl,-rpath,.:\'$$\'ORIGIN"]
                        }
                    }
                 ]
            ],
            "include_dirs": ["..", "../.."],
            "sources": ["questinterface_wrap.cxx"]
        }
    ]
}
