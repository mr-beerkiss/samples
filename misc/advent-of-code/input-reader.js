const readline = require("readline");

const noop = () => {};

function getLineReader(onLineFn, onCloseFn) {
  const rl = readline.createInterface({
    input: process.stdin,
    crlfDelay: Infinity
  });
  rl.on("line", typeof onLineFn === 'function' ? onLineFn : noop);
  rl.on("close", typeof onCloseFn === 'function' ? onCloseFn : noop);
  return rl;
}

module.exports = getLineReader;

