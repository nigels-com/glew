if ( NOT DEFINED CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Build type" )
endif ()

project (glew)

cmake_minimum_required (VERSION 2.4)

if (COMMAND cmake_policy)
  cmake_policy (SET CMP0003 NEW)
endif()

option (BUILD_UTILS "utilities" ON)

set (GLEW_VERSION "1.12.0")

set (GLEW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (WIN32)
  set (GLEW_LIB_NAME glew32)
else ()
  set (GLEW_LIB_NAME GLEW)
  set (DLL_PREFIX lib)
endif ()

find_package (OpenGL REQUIRED)
set (GLEW_LIBRARIES ${OPENGL_LIBRARIES})

add_definitions (-DGLEW_BUILD -DGLEW_NO_GLU)

include_directories (${GLEW_DIR}/include)

add_library (glew SHARED ${GLEW_DIR}/src/glew.c)
add_library (glew_s STATIC ${GLEW_DIR}/src/glew.c)
target_link_libraries (glew ${GLEW_LIBRARIES})
target_link_libraries (glew_s ${GLEW_LIBRARIES})
set_target_properties (glew PROPERTIES OUTPUT_NAME ${GLEW_LIB_NAME})
set_target_properties (glew_s PROPERTIES OUTPUT_NAME ${GLEW_LIB_NAME})
set_target_properties (glew PROPERTIES PREFIX "${DLL_PREFIX}")
set_target_properties (glew_s PROPERTIES PREFIX lib)

add_library(glewmx SHARED ${GLEW_DIR}/src/glew.c )
add_library(glewmx_s STATIC ${GLEW_DIR}/src/glew.c )
target_link_libraries (glewmx ${GLEW_LIBRARIES})
target_link_libraries (glewmx_s ${GLEW_LIBRARIES})
set_target_properties (glewmx PROPERTIES COMPILE_FLAGS "-DGLEW_MX" OUTPUT_NAME ${GLEW_LIB_NAME}mx)
set_target_properties (glewmx_s PROPERTIES COMPILE_FLAGS "-DGLEW_MX" OUTPUT_NAME ${GLEW_LIB_NAME}mx)
set_target_properties (glewmx PROPERTIES PREFIX "${DLL_PREFIX}")
set_target_properties (glewmx_s PROPERTIES PREFIX lib)

install ( TARGETS glew glew_s glewmx glewmx_s
          RUNTIME DESTINATION bin
          LIBRARY DESTINATION lib${LIB_SUFFIX}
          ARCHIVE DESTINATION lib${LIB_SUFFIX}
)

if (BUILD_UTILS)
  add_executable (glewinfo ${GLEW_DIR}/src/glewinfo.c)
  target_link_libraries (glewinfo glew)

  add_executable (visualinfo ${GLEW_DIR}/src/visualinfo.c)
  target_link_libraries (visualinfo glew)

  install ( TARGETS glewinfo visualinfo
            DESTINATION bin)
endif ()

set (prefix ${CMAKE_INSTALL_PREFIX})
set (exec_prefix \${prefix})
set (libdir \${prefix}/lib)
set (includedir \${prefix}/include)
set (includedir \${prefix}/include)
set (version ${GLEW_VERSION})
set (libname ${GLEW_LIB_NAME})
set (cflags)
set (requireslib glu)
configure_file (${GLEW_DIR}/glew.pc.in ${GLEW_DIR}/glew.pc @ONLY)
set (cflags "-DGLEW_MX")
set (libname ${GLEW_LIB_NAME}mx)
configure_file (${GLEW_DIR}/glew.pc.in ${GLEW_DIR}/glewmx.pc @ONLY)

install(FILES ${GLEW_DIR}/glew.pc ${GLEW_DIR}/glewmx.pc
        DESTINATION lib/pkgconfig
)
