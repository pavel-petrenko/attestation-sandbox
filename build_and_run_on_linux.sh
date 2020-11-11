#!/bin/bash

rm -rvf ./out
mkdir -pv out
cd out
cmake ../
make
./validatejwt.exe
