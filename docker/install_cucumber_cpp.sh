#!/bin/bash

git clone https://github.com/cucumber/cucumber-cpp.git
cd cucumber-cpp
cmake -B build . -DCUKE_ENABLE_QT=OFF
cd build
make -j4
make install


