const readline = require("readline");
const fs = require("fs");

const rl = readline.createInterface({
  input: fs.createReadStream("ids.txt"),
  crlfDelay: Infinity
});

const ids = [];

rl.on("line", line => {
  ids.push(line);
});

rl.on("close", () => {
  //console.log(ids.length);
  let match2 = 0;
  let match3 = 0;

  const charMaps = ids.map(id => {
    const charArray = Array.from(id);
    const charMap = {};

    for (let i = 0; i < charArray.length; i += 1) {
      const char = charArray[i];
      if (char in charMap) {
        charMap[char] += 1;
      } else {
        charMap[char] = 1;
      }
    }

    return charMap;
  });

  charMaps.forEach(map => {
    const keys = Object.keys(map);

    if (keys.find(k => map[k] === 3)) {
      match3 += 1;
    }

    if (keys.find(k => map[k] === 2)) {
      match2 += 1;
    }
  });

  console.log(match2 * match3);
});
