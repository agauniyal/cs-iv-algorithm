#!/usr/bin/env bash

set -ex

mkdir -p build
cd build/
cmake ..
make
./bin/tests.o
