console.log("Hello world!");

// const { querySelector } = document;

function recv({data}) {
  document.querySelector('.js-hook').textContent = data;
}

let fibWorker;

function createWokers() {
  if (window.Worker) {
    // console.log("Great news everyone, Web Workers are supported!");
    // const pulseWorker = new Worker("worker.js");
    // pulseWorker.onmessage = recv;

    fibWorker = new Worker("fib_worker.js");
    fibWorker.onmessage = fibWorkerRecv;
  }


}


let inputField;
let fibResult;
let fibTime;

function fibWorkerRecv({data}) {
  if (!fibResult) fibResult = document.querySelector('.js-hook-result');
  if (!fibTime) fibTime = document.querySelector('.js-hook-time');

  const { result, resultTime } = data;

  fibResult.textContent = formatBigNumber(result);
  fibTime.textContent = formatBigNumber(resultTime);
}

function formatBigNumber(number) {
  const s = Array.from(number.toString(10));
  if (s.length < 4) return s.join("");

  const res = [];

  for (let i=s.length-1, j=0; i >= 0; i -= 1, j += 1) {
    if (j > 0 && j % 3 === 0) {
      res.push(",");
    }
    res.push(s[i]);
    
  }

  return res.reverse().join("");
}

function buttonHook(e) {
  if (!inputField) inputField = document.querySelector('.js-hook-field');
  const { value } = inputField;
  console.log(`Value of field: ${value}`);

  
  
  // const startTime = Date.now();
  // fibResult.textContent = fib(value);
  // const endTime = Date.now();

  fibWorker.postMessage({ term: value });


  
  // fibTime.textContent = `${endTime - startTime}ms`;

}

function fib(term) {
  if (term <= 1) {
    return term;
  }

  return fib(term-2) + fib(term-1);
}

let clickedField;

let count = 0;

function hook2(e) {
  if (!clickedField) clickedField = document.querySelector('.js-hook-interactive-field');

  count += 1;

  clickedField.textContent = count;
}

window.onload = () => {
  console.log("Window onload");
  createWokers();
  document.querySelector(".js-hook-button").addEventListener("click", buttonHook);
  document.querySelector(".js-hook-interactive-button").addEventListener("click", hook2);
  
};
