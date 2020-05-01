console.log("Hello worker!");

// console.log(self);

// setInterval(() => console.log("Hello interval"));

let counter = 0;
let timeSince = Date.now();
let rate = 1000;

function pulse() {
  const timeNow = Date.now();
  if (timeNow - timeSince >= rate) {
    console.log("Pulse");
    counter += 1;    
    timeSince = timeNow;
    postMessage(counter);
  }
  
  self.requestAnimationFrame(pulse);
}


self.requestAnimationFrame(pulse);