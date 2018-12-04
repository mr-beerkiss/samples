const input = require("./frequencies.json");

const results = [];
const length = input.length;
let currentFrequency = 0;
let match = undefined;

while (!match) {
  for (let index = 0; index < length; index += 1) {
    currentFrequency += input[index];
    match = results.find(f => f === currentFrequency);
    if (match) break;
    results.push(currentFrequency);
  }
}

console.log(`Match: ${match}`);
