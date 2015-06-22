#!/bin/sh

# This script tests the CMake build:
#
# - builds the main CMakeLists.txt
# - builds and runs a small test app in a separate build tree so
#   the config-module is tested, too
#
# Options (environment variables):
#
# - The variable BUILD_SHARED_LIBS will be forwarded to the CMake project
#   that builds and installs the GLEW libraries. Set BUILD_SHARED_LIBS to
#   ON or OFF to install only static or shared libs. Leave it unset to
#   install both.
#
#   Note: BUILD_SHARED_LIBS controls only what to install not what to build.
#
# - GLEW_USE_STATIC_LIBS will be forwarded to the test project that calls
#   `find_package` to find GLEW. Set GLEW_USE_STATIC LIBS to ON or OFF force
#   finding the shared or static versions of GLEW. Leave it unset to find
#   the shared or what is available.
#
# Examples:
#
# Build & install shared + static, find default (shared)
#
#    ./cmake-testbuild.shh
#
# Build & install shared + static, find static
#
#    GLEW_USE_STATIC_LIBS=ON ./cmake-testbuild.sh
#
# Install static only (still build both)
#
#    BUILD_SHARED_LIBS=OFF ./cmake-testbuild.sh
#

set -ex

rm -rf out/include
rm -rf out/lib*
rm -rf out/bin

if [ -n "$BUILD_SHARED_LIBS" ]; then
    bsl=-DBUILD_SHARED_LIBS=$BUILD_SHARED_LIBS
else
    bsl=-UBUILD_SHARED_LIBS
fi

if [ -n "$GLEW_USE_STATIC_LIBS" ]; then
    gusl=-DGLEW_USE_STATIC_LIBS=$GLEW_USE_STATIC_LIBS
else
    gusl=-UGLEW_USE_STATIC_LIBS
fi

cmake -Hbuild/cmake -Bout/build/glew -DCMAKE_INSTALL_PREFIX=${PWD}/out -DCMAKE_BUILD_TYPE=Debug $bsl
cmake --build out/build/glew --target install --config Debug
cmake out/build/glew -DCMAKE_BUILD_TYPE=Release
cmake --build out/build/glew --target install --config Release --clean-first

cmake -Hbuild/cmake/testbuild -Bout/build/cmake-testbuild -DCMAKE_INSTALL_PREFIX=${PWD}/out -DCMAKE_PREFIX_PATH=${PWD}/out -DCMAKE_BUILD_TYPE=Debug $gusl
cmake --build out/build/cmake-testbuild --target install --config Debug

cmake out/build/cmake-testbuild -DCMAKE_BUILD_TYPE=Release
cmake --build out/build/cmake-testbuild --target install --config Release --clean-first

export LD_LIBRARY_PATH=${PWD}/out/lib:$LD_LIBRARY_PATH

out/bin/cmake-test_d
out/bin/cmake-test
