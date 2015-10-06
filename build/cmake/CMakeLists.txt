if ( NOT DEFINED CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Build type" )
endif ()

project (glew)

cmake_minimum_required (VERSION 2.4)

if (COMMAND cmake_policy)
  cmake_policy (SET CMP0003 NEW)
endif()

set(CMAKE_DEBUG_POSTFIX d)

option (BUILD_UTILS "utilities" ON)
option (GLEW_REGAL "Regal mode" FALSE)
option (GLEW_OSMESA "OSMesa mode" FALSE)

set (GLEW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# get version from config/version
file (STRINGS ${GLEW_DIR}/config/version  _VERSION_MAJOR_STRING REGEX "GLEW_MAJOR[ ]*=[ ]*[0-9]+.*")
string (REGEX REPLACE "GLEW_MAJOR[ ]*=[ ]*([0-9]+)" "\\1" CPACK_PACKAGE_VERSION_MAJOR ${_VERSION_MAJOR_STRING})
file (STRINGS ${GLEW_DIR}/config/version  _VERSION_MINOR_STRING REGEX "GLEW_MINOR[ ]*=[ ]*[0-9]+.*")
string (REGEX REPLACE "GLEW_MINOR[ ]*=[ ]*([0-9]+)" "\\1" CPACK_PACKAGE_VERSION_MINOR ${_VERSION_MINOR_STRING})
file (STRINGS ${GLEW_DIR}/config/version  _VERSION_PATCH_STRING REGEX "GLEW_MICRO[ ]*=[ ]*[0-9]+.*")
string (REGEX REPLACE "GLEW_MICRO[ ]*=[ ]*([0-9]+)" "\\1" CPACK_PACKAGE_VERSION_PATCH ${_VERSION_PATCH_STRING})
set (GLEW_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

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

add_definitions (-DGLEW_NO_GLU)

#### Regal mode ####

if (GLEW_REGAL)
  if (WIN32)
    set (REGAL_LIB_NAME regal32)
  else ()
    set (REGAL_LIB_NAME Regal)
  endif ()
  add_definitions (-DGLEW_REGAL)
  set (GLEW_LIBRARIES ${REGAL_LIB_NAME})
endif ()

#### OSMesa mode ####

if (GLEW_OSMESA)
  if (WIN32)
    set (OSMESA_LIB_NAME osmesa)
  else ()
    set (OSMESA_LIB_NAME OSMesa)
  endif ()
  add_definitions (-DGLEW_OSMESA)
  set (GLEW_LIBRARIES ${OSMESA_LIB_NAME} ${OPENGL_LIBRARIES})
endif ()

#### GLEW ####

include_directories (${GLEW_DIR}/include)

set (GLEW_SRC_FILES ${GLEW_DIR}/src/glew.c)

if (WIN32)
  list (APPEND GLEW_SRC_FILES ${GLEW_DIR}/build/glew.rc)
endif ()

add_library (glew SHARED ${GLEW_SRC_FILES})
set_target_properties (glew PROPERTIES COMPILE_DEFINITIONS "GLEW_BUILD" OUTPUT_NAME "${GLEW_LIB_NAME}" PREFIX "${DLL_PREFIX}")
add_library (glew_s STATIC ${GLEW_SRC_FILES})
set_target_properties (glew_s PROPERTIES COMPILE_DEFINITIONS "GLEW_STATIC" OUTPUT_NAME "${GLEW_LIB_NAME}" PREFIX lib)
target_link_libraries (glew ${GLEW_LIBRARIES})
target_link_libraries (glew_s ${GLEW_LIBRARIES})

add_library(glewmx SHARED ${GLEW_SRC_FILES})
set_target_properties (glewmx PROPERTIES COMPILE_DEFINITIONS "GLEW_BUILD;GLEW_MX" OUTPUT_NAME "${GLEW_LIB_NAME}mx" PREFIX "${DLL_PREFIX}")
add_library(glewmx_s STATIC ${GLEW_SRC_FILES})
set_target_properties (glewmx_s PROPERTIES COMPILE_DEFINITIONS "GLEW_STATIC;GLEW_MX" OUTPUT_NAME "${GLEW_LIB_NAME}mx" PREFIX lib)
target_link_libraries (glewmx ${GLEW_LIBRARIES})
target_link_libraries (glewmx_s ${GLEW_LIBRARIES})

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  set(MAYBE_EXPORT "")
else()
  target_compile_definitions(glew_s INTERFACE "GLEW_STATIC")
  target_compile_definitions(glewmx INTERFACE "GLEW_MX")
  target_compile_definitions(glewmx_s INTERFACE "GLEW_STATIC;GLEW_MX")
  foreach(t glew glew_s glewmx glewmx_s)
    target_include_directories(${t} PUBLIC $<INSTALL_INTERFACE:include>)
  endforeach()
  set(MAYBE_EXPORT EXPORT glew-targets)
endif()

set(targets_to_install "")
if(NOT DEFINED BUILD_SHARED_LIBS OR BUILD_SHARED_LIBS)
  list(APPEND targets_to_install glew glewmx)
endif()

if(NOT DEFINED BUILD_SHARED_LIBS OR NOT BUILD_SHARED_LIBS)
  list(APPEND targets_to_install glew_s glewmx_s)
endif()

install ( TARGETS ${targets_to_install}
          ${MAYBE_EXPORT}
          RUNTIME DESTINATION bin
          LIBRARY DESTINATION lib${LIB_SUFFIX}
          ARCHIVE DESTINATION lib${LIB_SUFFIX}
)

if (BUILD_UTILS)
  set (GLEWINFO_SRC_FILES ${GLEW_DIR}/src/glewinfo.c)
  if (WIN32)
    list (APPEND GLEWINFO_SRC_FILES ${GLEW_DIR}/build/glewinfo.rc)
  endif ()
  add_executable (glewinfo ${GLEWINFO_SRC_FILES})
  target_link_libraries (glewinfo glew)

  set (VISUALINFO_SRC_FILES ${GLEW_DIR}/src/visualinfo.c)
  if (WIN32)
    list (APPEND VISUALINFO_SRC_FILES ${GLEW_DIR}/build/visualinfo.rc)
  endif ()
  add_executable (visualinfo ${VISUALINFO_SRC_FILES})
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

install (FILES
    ${GLEW_DIR}/include/GL/wglew.h
    ${GLEW_DIR}/include/GL/glew.h
    ${GLEW_DIR}/include/GL/glxew.h
    DESTINATION include/GL)

if(MAYBE_EXPORT)
  install(EXPORT glew-targets DESTINATION lib/cmake/glew
    NAMESPACE GLEW::)
  install(FILES
      ${CMAKE_CURRENT_SOURCE_DIR}/glew-config.cmake
      ${CMAKE_CURRENT_SOURCE_DIR}/CopyImportedTargetProperties.cmake
    DESTINATION lib/cmake/glew)
endif()
