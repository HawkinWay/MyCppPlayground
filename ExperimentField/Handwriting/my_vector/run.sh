#! /bin/sh

cmake . -B cmake-build ; cd cmake-build ; make ; ./main ; cd .. ; rm -rf cmake-build