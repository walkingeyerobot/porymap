#!/bin/bash
pushd src
qmake -qt=qt5
make
popd
