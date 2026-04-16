#! /bin/sh

g++ -c thrd.cpp main.cpp ; g++ thrd.o main.o -o sing ; ./sing
