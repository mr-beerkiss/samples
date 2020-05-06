#!/usr/bin/env bash

MAX_PRIMES=10000

echo "Recompile all the things"
clang++ -std=c++11 -g prime_test.cpp -o prime_test
rustc -C opt-level=3 primes-rs.rs

printf '\nC++ version\n'
time ./prime_test "${MAX_PRIMES}"

printf '\nJS version\n'
time node  prime-js.js "${MAX_PRIMES}"

printf '\nRust version\n'
time ./primes-rs "${MAX_PRIMES}"
