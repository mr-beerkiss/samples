"use strict";

function IsPrime(num) {
  if (num < 4) return true;

  if (num % 2 == 0) return false;

  for (let d = num - 1; d > 2; --d) if (num % d == 0) return false;

  return true;
}

function GetPrimes(maxPrimes) {
  const results = [];

  if (maxPrimes > 0) results.push(1);

  if (maxPrimes > 1) results.push(2);

  if (maxPrimes > 2) {
    let foundPrimes = 2;
    let next = 3;
    while (foundPrimes < maxPrimes) {
      if (IsPrime(next)) {
        results.push(next);
        foundPrimes += 1;
      }
      next += 2;
    }
  }

  return results;
}

const maxPrimes = process.argv[2];

const res = GetPrimes(maxPrimes);

// console.log(res.join(" "));
console.log(`Found ${res.length} primes!`);
