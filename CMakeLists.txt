# -*- mode:cmake -*-
cmake_minimum_required (VERSION 2.8)

# Detect build type, fallback to release and throw a warning if use didn't specify any
if(NOT CMAKE_BUILD_TYPE)
  message(WARNING "Build type not set, falling back to Release mode.
 To specify build type use:
 -DCMAKE_BUILD_TYPE=<mode> where <mode> is Debug or Release.")
 set(CMAKE_BUILD_TYPE "Release" CACHE STRING
       "Choose the type of build, options are: Debug Release."
       FORCE)
endif(NOT CMAKE_BUILD_TYPE)

project(gen_audit_interface)

file(STRINGS "VERSION" GEN_AUDIT_VERSION)

# Initialize CXXFLAGS.
if("${CMAKE_VERSION}" VERSION_GREATER 3.1.0)
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
  set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
  set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -std=c++11")
  set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} ${MY_CXX_WARNING_FLAGS} -DCMDVERSION=${GEN_AUDIT_VERSION}")
set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g ${MY_CXX_WARNING_FLAGS} -DDEBUG_0 -DCMDVERSION=${GEN_AUDIT_VERSION}")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG ${MY_CXX_WARNING_FLAGS} -DCMDVERSION=${GEN_AUDIT_VERSION}")
set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG ${MY_CXX_WARNING_FLGAS} -DCMDVERSION=${GEN_AUDIT_VERSION}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g ${MY_CXX_WARNING_FLAGS} -DCMDVERSION=${GEN_AUDIT_VERSION}")

add_subdirectory(antlr4cpp)

set(antlr4-gen_audit-GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenLexer.cpp 
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenParser.cpp
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenParserBaseListener.cpp
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenParserBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenParserListener.cpp
  ${PROJECT_SOURCE_DIR}/syntax/generated/AuditGenParserVisitor.cpp
)
set(BIN_DIRECTORY "${PROJECT_SOURCE_DIR}/test/bin/")

foreach(src_file ${antlr4-gen_audit-GENERATED_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach(src_file ${antlr4-gen_audit-GENERATED_SRC})

add_compile_options(-gdwarf -g3 -Wall)
add_custom_target(Generategen_auditParser DEPENDS ${antlr4-gen_audit-GENERATED_SRC})

include_directories(
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src/misc
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src/atn
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src/dfa
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src/tree
  ${PROJECT_SOURCE_DIR}/antlr4cpp/src/support
  ${PROJECT_SOURCE_DIR}/syntax/generated
  ${PROJECT_SOURCE_DIR}/parser
  ${PROJECT_SOURCE_DIR}/
  )

#file(GLOB antlr4-gen_audit_SRC "${PROJECT_SOURCE_DIR}/gen_audit/generated/*")
file(GLOB_RECURSE PARSER_SRC "${PROJECT_SOURCE_DIR}/parser/*.cpp")
file(GLOB_RECURSE AST_SRC "${PROJECT_SOURCE_DIR}/ast/*.cpp")
set(antlr4-gen_audit_SRC 
  ${PARSER_SRC}
  ${AST_SRC}
  ${PROJECT_SOURCE_DIR}/main/main.cpp
  ${antlr4-gen_audit-GENERATED_SRC}
  )

foreach(src_file ${antlr4-gen_audit_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach(src_file ${antlr4-gen_audit_SRC})

# executable file name
add_executable(gen_audit
  ${antlr4-gen_audit_SRC}
  )

add_dependencies(gen_audit Generategen_auditParser)

link_directories(
  ${PROJECT_SOURCE_DIR}/dist
)
target_link_libraries(gen_audit antlr4_static)

set_target_properties(gen_audit
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIRECTORY}
)
