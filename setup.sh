#!/bin/bash

if [ ! -d obj ]; then
    #statements
    echo "create object folder ./obj"
    mkdir obj
fi

if [ ! -d bin ]; then
    #statements
    echo "create binary folder ./bin"
    mkdir bin
fi

make

