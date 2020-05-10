#!/usr/bin/env bash

FACTORIAL=100

echo "Recompile all the things"
clang++ -std=c++11 -g factorial.cpp -o factorial
rustc -C opt-level=3 factorial-rs.rs

printf '\nC++ version\n'
time ./factorial "${FACTORIAL}"

printf '\nJS version\n'
time node  factorial-js.js "${FACTORIAL}"

printf '\nRust version\n'
time ./factorial-rs "${FACTORIAL}"
