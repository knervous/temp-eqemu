cmake_minimum_required(VERSION 3.12)

project(node_quests)

file(GLOB NODE_QUEST_SOURCES "${CMAKE_SOURCE_DIR}/zone/node_quests/*.cpp")
file(GLOB NODE_QUEST_HEADERS "${CMAKE_SOURCE_DIR}/zone/node_quests/*.h")

# Include Node.js headers and our headers
include_directories(
    ${CMAKE_SOURCE_DIR}/zone
    ${CMAKE_SOURCE_DIR}/submodules/nodejs/src
    ${CMAKE_SOURCE_DIR}/submodules/nodejs/deps/v8/include
    ${CMAKE_SOURCE_DIR}/submodules/nodejs/deps/uv/include
)
if(MSVC)
    file(GLOB NODE_LIBRARIES "${CMAKE_SOURCE_DIR}/submodules/nodejs/out/Release/*.lib")
else()
    file(GLOB NODE_LIBRARIES "${CMAKE_SOURCE_DIR}/submodules/nodejs/out/Release/*.a")
endif()

add_library(${PROJECT_NAME} SHARED ${NODE_QUEST_SOURCES} ${NODE_QUEST_HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

target_link_libraries(${PROJECT_NAME} ${NODE_LIBRARIES} zonelib ${PERL_LIBRARY})

target_compile_definitions(${PROJECT_NAME} PRIVATE NODE_WANT_INTERNALS=1 HAVE_INSPECTOR=1 NODE_QUEST_EXPORT=1)

# Remove reference to perl and lua in this
add_compile_options(
  "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-UEMBPERL>"
)
add_compile_options(
  "$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:-ULUA_EQEMU>"
)

# Compiler-specific logic
if(MSVC)
    # Set .dll extension for MSVC compiler
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")
else()
    # Set .so extension for Unix-like systems (default behavior)
endif()

# If using MSVC and building Node.js as a DLL, make sure to define NODE_SHARED as a preprocessor definition
if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE NODE_SHARED=1)
endif()

SET(BUILD_DIR "${CMAKE_SOURCE_DIR}/build/bin")

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR} # For static libs or import libs on Windows
    RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR} # For Windows DLLs
)