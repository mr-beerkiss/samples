function factorial(n) {
  if (n === 1) return n;
  else return n * factorial(n - 1);
}

(function () {
  const num = process.argv[2];
  const res = factorial(num);
  console.log(`[JS] - factorial${num} = ${res}`);
})();
