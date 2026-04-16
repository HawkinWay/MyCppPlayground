#! /bin/sh

g++ -c pt.cpp main.cpp ; g++ pt.o main.o -o exc ; ./exc
