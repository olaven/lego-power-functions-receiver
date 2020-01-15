#!/usr/bin/env bash

clang++ -std=c++11 tests/test-lpf-receiver.cpp -o tests/tests.out
./tests/tests.out
