if ( NOT DEFINED CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Build type" )
endif ()

project (GLEW)

cmake_minimum_required (VERSION 2.4)

if (COMMAND cmake_policy)
  cmake_policy (SET CMP0003 NEW)
endif()

option (BUILD_SHARED_LIBS "build shared/static libs" ON)

set (GLEW_VERSION "1.12.0")

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (WIN32)
  set(GLEW_LIB_NAME glew32)
else ()
  set(GLEW_LIB_NAME GLEW)
  set(DLL_PREFIX lib)
endif ()

find_package (OpenGL REQUIRED)
set (GLEW_LIBRARIES ${OPENGL_LIBRARIES})

if (UNIX)
 find_package (X11 REQUIRED)
 list (APPEND GLEW_LIBRARIES ${X11_LIBRARIES})
endif ()

add_definitions (-DGLEW_BUILD -DGLEW_NO_GLU)

include_directories (${PROJECT_SOURCE_DIR}/include)

add_library (glew src/glew.c)
target_link_libraries(glew ${GLEW_LIBRARIES})
set_target_properties (glew PROPERTIES OUTPUT_NAME ${GLEW_LIB_NAME})
if (BUILD_SHARED_LIBS)
  set_target_properties(glew PROPERTIES PREFIX "${DLL_PREFIX}")
else ()
  set_target_properties(glew PROPERTIES PREFIX lib)
endif ()

add_library(glew_mx src/glew.c )
target_link_libraries (glew_mx ${GLEW_LIBRARIES})
set_target_properties (glew_mx PROPERTIES COMPILE_FLAGS "-DGLEW_MX" OUTPUT_NAME ${GLEW_LIB_NAME}mx)

if (BUILD_SHARED_LIBS)
  set_target_properties (glew_mx PROPERTIES PREFIX "${DLL_PREFIX}")
else ()
  set_target_properties (glew_mx PROPERTIES PREFIX lib)
endif ()

add_executable (glewinfo src/glewinfo.c)
target_link_libraries(glewinfo glew)

add_executable(visualinfo src/visualinfo.c)
target_link_libraries(visualinfo glew)


install ( TARGETS glew glew_mx glewinfo visualinfo
          RUNTIME DESTINATION bin
          LIBRARY DESTINATION lib${LIB_SUFFIX}
          ARCHIVE DESTINATION lib${LIB_SUFFIX}
)

set (prefix ${CMAKE_INSTALL_PREFIX})
set (exec_prefix \${prefix})
set (libdir \${prefix}/lib)
set (includedir \${prefix}/include)
set (includedir \${prefix}/include)
set (version ${GLEW_VERSION})
set (libname ${GLEW_LIB_NAME})
set (cflags)
set (requireslib glu)
configure_file (glew.pc.in ${CMAKE_BINARY_DIR}/glew.pc @ONLY)
set (cflags "-DGLEW_MX")
set (libname ${GLEW_LIB_NAME}mx)
configure_file (glew.pc.in ${CMAKE_BINARY_DIR}/glewmx.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/glew.pc ${CMAKE_BINARY_DIR}/glewmx.pc
        DESTINATION lib/pkgconfig
)
