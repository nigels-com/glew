#!/bin/sh

set -e

if [ ! -d $1 ] ; then
    mkdir $1
    cd $1
fi

wget                                                    \
    --mirror                                            \
    --no-parent                                         \
    --no-host-directories                               \
    --cut-dirs=3                                        \
    --accept=txt,html                                   \
    http://oss.sgi.com/projects/ogl-sample/registry/

sed -i -e '7s/\<ATI_/GL_ATI_/' ATI/texture_env_combine3.txt
