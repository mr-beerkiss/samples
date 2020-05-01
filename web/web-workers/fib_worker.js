console.log("Hello Fib!");


onmessage = ({ data }) => {
  // console.log(args);
  // postMessage({result: fib(data.term)});
  const { term } = data;

  console.log(`START - fib_worker caluculating ${term}th term in the fibonnaci sequence`);

  const startTime = Date.now();
  const result = fib(term);
  const endTime = Date.now();

  console.log(`FINISHED - fib_worker caluculating ${term}th term in the fibonnaci sequence`);

  postMessage({result, resultTime: endTime - startTime});

};

function fib(term) {
  if (term <= 1) {
    return term;
  }

  return fib(term-2) + fib(term-1);
}