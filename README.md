# GLEW - The OpenGL Extension Wrangler Library

![](http://glew.sourceforge.net/glew.png)

http://glew.sourceforge.net/

https://github.com/nigels-com/glew

[![Build Status](https://travis-ci.org/nigels-com/glew.svg?branch=master)](https://travis-ci.org/nigels-com/glew)
[![Gitter](https://badges.gitter.im/nigels-com/glew.svg)](https://gitter.im/nigels-com/glew?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

## Downloads

Current release is [1.13.0](https://sourceforge.net/projects/glew/files/glew/1.13.0/).
[(Change Log)](http://glew.sourceforge.net/log.html)

Sources available as 
[ZIP](https://sourceforge.net/projects/glew/files/glew/1.13.0/glew-1.13.0.zip/download) or
[TGZ](https://sourceforge.net/projects/glew/files/glew/1.13.0/glew-1.13.0.tgz/download).

Windows binaries for [32-bit and 64-bit](https://sourceforge.net/projects/glew/files/glew/1.13.0/glew-1.13.0-win32.zip/download).

### Recent snapshots

Snapshots may contain new features, bug-fixes or new OpenGL extensions ahead of tested, official releases.

[glew-20150805.tgz](http://sourceforge.net/projects/glew/files/glew/snapshots/glew-20150805.tgz/download)

[glew-20150124.tgz](http://sourceforge.net/projects/glew/files/glew/snapshots/glew-20150124.tgz/download)

## Build

From a downloaded tarball or zip archive:

### Linux and Mac

#### Using GNU Make

##### Install build tools

Debian/Ubuntu/Mint:    `$ sudo apt-get install build-essential libXmu-dev libXi-dev libgl-dev git`

RedHat/CentOS/Fedora:  `$ sudo yum install libXmu-devel libXi-devel libGL-devel git`

##### Build

	$ make
	$ sudo make install
	$ make clean

Targets:    `all, glew.lib, glew.bin, clean, install, uninstall`

Variables:  `SYSTEM=linux-clang, GLEW_DEST=/usr/local, STRIP=`

#### Using cmake

*CMake 2.8.12 or higher is required.*

##### Install build tools

Debian/Ubuntu/Mint:   `$ sudo apt-get install build-essential libXmu-dev libXi-dev libgl-dev git cmake`

RedHat/CentOS/Fedora: `$ sudo yum install libXmu-devel libXi-devel libGL-devel git cmake`

##### Build

	$ cd build
	$ cmake ./cmake 
	$ make -j4

### Windows

Use the provided Visual Studio project file in build/vc12/

## glewinfo

`glewinfo` is a command-line tool useful for inspecting the capabilities of an
OpenGL implementation and GLEW support for that.  Please include the output of
`glewinfo` with bug reports, as appropriate.	

	---------------------------
	    GLEW Extension Info
	---------------------------

	GLEW version 2.0.0
	Reporting capabilities of pixelformat 3
	Running on a Intel(R) HD Graphics 3000 from Intel
	OpenGL version 3.1.0 - Build 9.17.10.4229 is supported

	GL_VERSION_1_1:                                                OK
	---------------

	GL_VERSION_1_2:                                                OK
	---------------
	  glCopyTexSubImage3D:                                         OK
	  glDrawRangeElements:                                         OK
	  glTexImage3D:                                                OK
	  glTexSubImage3D:                                             OK
	
	...

## Code Generation

A Unix or Mac environment is neded for building GLEW from scratch to
include new extensions, or customize the code generation. The extension
data is regenerated from the top level source directory with:

	make extensions

An alternative to generating the GLEW sources from scratch is to
download a pre-generated (unsupported) snapshot:

https://sourceforge.net/projects/glew/files/glew/snapshots/

Travis-built snapshots are also available:

https://glew.s3.amazonaws.com/index.html
