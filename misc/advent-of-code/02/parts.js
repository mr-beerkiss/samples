const readline = require("readline");
const fs = require("fs");

const rl = readline.createInterface({
  input: fs.createReadStream("ids.txt"),
  crlfDelay: Infinity
});

const ids = [];

rl.on("line", line => {
  ids.push(Array.from(line));
});

rl.on("close", () => {
  let current, next;
  outer: while (ids.length) {
    current = ids.shift();
    inner: for (let i = 0; i < ids.length; i += 1) {
      next = ids[i];
      let differences = 0;
      for (let c = 0; c < current.length; c += 1) {
        if (current[c] !== next[c]) {
          differences += 1;
          if (differences >= 2) {
            continue inner;
          }
        }
      }
      if (differences === 1) {
        break outer;
      }
    }
  }

  let res = [];
  for (let char = 0; char < current.length; char += 1) {
    if (current[char] === next[char]) {
      res.push(current[char]);
    } else {
      console.log("the different characeter is ", current[char]);
    }
  }

  console.log(res.join(""));
});
