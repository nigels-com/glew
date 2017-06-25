import os
from conans import ConanFile, CMake
from conans.tools import os_info, SystemPackageTool, ConanException
# from conans import tools, VisualStudioBuildEnvironment
from conans.tools import build_sln_command, vcvars_command, replace_in_file

class GlewConan(ConanFile):
    name = "glew"
    version = "master"
    description = "The GLEW library"
    generators = "cmake", "txt"
    settings = "os", "arch", "build_type", "compiler"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    url="http://github.com/nigels-com/glew"
    license="https://github.com/nigels-com/glew#copyright-and-licensing"
    if os.path.isfile("Makefile"):
        exports = "*"
    else:
        exports = os.sep.join([".", "..", "..", "*"])
        
    def system_requirements(self):
        if os_info.is_linux:
            if os_info.with_apt:
                installer = SystemPackageTool()
                installer.install("build-essential")
                installer.install("libxmu-dev")
                installer.install("libxi-dev")
                installer.install("libgl-dev")
                installer.install("libosmesa-dev")
                installer.install("libglu1-mesa-dev")
            elif os_info.with_yum:
                installer = SystemPackageTool()
                installer.install("libXmu-devel")
                installer.install("libXi-devel")
                installer.install("libGL-devel")
                installer.install("mesa-libGLU-devel")
            else:
                self.output.warn("Could not determine Linux package manager, skipping system requirements installation.")

    def configure(self):
        del self.settings.compiler.libcxx

    def build(self):
        if self.settings.compiler == "Visual Studio":
            raise ConanException("Windows builds do not work yet.")
          #  env = VisualStudioBuildEnvironment(self)
          #  with tools.environment_append(env.vars):
          #      version = min(12, int(self.settings.compiler.version.value))
          #      version = 10 if version == 11 else version
          #      cd_build = "cd %s\\%s\\build\\vc%s" % (self.conanfile_directory, self.ZIP_FOLDER_NAME, version)
          #      build_command = build_sln_command(self.settings, "glew.sln")
          #      vcvars = vcvars_command(self.settings)
          #      self.run("%s && %s && %s" % (vcvars, cd_build, build_command.replace("x86", "Win32")))
        else:
            if self.settings.os == "Windows":
                replace_in_file("%s/build/cmake/CMakeLists.txt" % self.conanfile_directory, \
                                "if(WIN32 AND (NOT MSVC_VERSION LESS 1600)", \
                                "if(WIN32 AND MSVC AND (NOT MSVC_VERSION LESS 1600)")
            self.run("make extensions")
            cmake = CMake(self)
            cmake.configure(source_dir="%s/build/cmake" % self.conanfile_directory, defs={"BUILD_UTILS": "OFF"})
            cmake.build()

    def package(self):
        self.copy("FindGLEW.cmake", ".", "%s/build/conan" % self.conanfile_directory, keep_path=False)
        self.copy("include/*", ".", ".", keep_path=True)
        self.copy("license*", src=".", dst="licenses",  ignore_case=True, keep_path=False)

        if self.settings.os == "Windows":
            if self.settings.compiler == "Visual Studio":
                if self.options.shared:
                    self.copy(pattern="*32.lib", dst="lib", keep_path=False)
                    self.copy(pattern="*32d.lib", dst="lib", keep_path=False)
                    self.copy(pattern="*.dll", dst="bin", keep_path=False)
                    self.copy(pattern="*.pdb", dst="bin", keep_path=False)
                else:
                    self.copy(pattern="*32s.lib", dst="lib", keep_path=False)
                    self.copy(pattern="*32sd.lib", dst="lib", keep_path=False)
            else:
                if self.options.shared:
                    self.copy(pattern="*32.dll.a", dst="lib", keep_path=False)
                    self.copy(pattern="*.dll", dst="bin", keep_path=False)
                else:
                    self.copy(pattern="*32.a", dst="lib", keep_path=False)
        elif self.settings.os == "Macos":
            if self.options.shared:
                self.copy(pattern="*.dylib", dst="lib", keep_path=False)
            else:
                self.copy(pattern="*.a", dst="lib", keep_path=False)
        else:
            if self.options.shared:
                self.copy(pattern="*.so", dst="lib", keep_path=False)
            else:
                self.copy(pattern="*.a", dst="lib", keep_path=False)

    def package_info(self):
        if self.settings.os == "Windows":
            self.cpp_info.libs = ['glew32']

            if not self.options.shared:
                self.cpp_info.defines.append("GLEW_STATIC")

            if self.settings.compiler == "Visual Studio":
                if not self.options.shared:
                    self.cpp_info.libs[0] += "s"
                    self.cpp_info.libs.append("OpenGL32.lib")
                    if self.settings.compiler.runtime != "MT":
                        self.cpp_info.exelinkflags.append('-NODEFAULTLIB:LIBCMTD')
                        self.cpp_info.exelinkflags.append('-NODEFAULTLIB:LIBCMT')
            else:
                self.cpp_info.libs.append("opengl32")
                
        else:
            self.cpp_info.libs = ['GLEW']
            if self.settings.os == "Macos":
                self.cpp_info.exelinkflags.append("-framework OpenGL")
            elif not self.options.shared:
                self.cpp_info.libs.append("GL")

        if self.settings.build_type == "Debug":
            self.cpp_info.libs[0] += "d"
