#!/usr/bin/env bash

set -ex

mkdir -p build
cd build/
cmake "$1" ..
make
