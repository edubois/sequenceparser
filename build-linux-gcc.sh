#!/bin/bash

if [ ! $BOOST_ROOT ]
then 
	echo 
	echo "In order to use bjam and build Duke, the BOOST_ROOT environment variable have to be set"
	echo "Edit and type the following command: export BOOST_ROOT=/your/path/to/boost/root/directory"
	echo "See README file for more informations."
	echo "Quit." 
	exit 1;
fi


if [ `getconf LONG_BIT` = "64" ]
then
    ADDRESS_MODEL=64
else
    ADDRESS_MODEL=32
fi

# boost build configuration
export BOOST_BUILD_PATH=$BOOST_ROOT/tools/build/v2
$BOOST_ROOT/bjam --toolset=gcc cflags=-fPIC cxxflags=-fPIC python=2.6 address-model=$ADDRESS_MODEL $*
