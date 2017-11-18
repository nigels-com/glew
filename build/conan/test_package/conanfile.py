from conans import ConanFile, CMake
import os

class TestGlew(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        self.run(os.sep.join([".","bin", "testGlew"]))

    def imports(self):
        if self.settings.os == "Windows":
            self.copy(pattern="*.dll", dst="bin", src="bin")
            self.copy(pattern="*.pdb", dst="bin", src="bin")
        if self.settings.os == "Macos":
            self.copy(pattern="*.dylib", dst="bin", src="lib")
