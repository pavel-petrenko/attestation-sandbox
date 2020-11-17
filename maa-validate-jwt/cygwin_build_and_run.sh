#!/bin/bash

# THIS IS NOT A WELL DEVELOPED SCRIPT, IT IS JUST A SET OF STEPS TO BUILD AND RUN "HELLO-WORLD"

rm -rvf ./out
mkdir out
cd out/
cmake ../
make
./maavalidatejwt.exe
