#!/bin/bash

gcc -ansi -Wall -c jdv.c
gcc -ansi -Wall jogodavida.c jdv.o -lncurses

