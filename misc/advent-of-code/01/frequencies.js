const input = require("./frequencies.json");

const result = input.reduce((acc, num) => (acc += num), 0);

console.log(result);
