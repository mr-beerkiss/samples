const getLineReader = require("../input-reader");

const material = [];
const claims = [];
const claimRegex = /#(\d+) @ (\d+),(\d+): (\d+)x(\d+)/;

const MAX_WIDTH = 1000;
const DEBUG = false;

function handleLine(line) {
  const claimComponents = line.match(claimRegex);
  let compIdx = 0;
  
  const raw = claimComponents[compIdx++];
  const id = parseInt(claimComponents[compIdx++], 10);
  const xOffset = parseInt(claimComponents[compIdx++], 10);
  const yOffset = parseInt(claimComponents[compIdx++], 10);
  const width = parseInt(claimComponents[compIdx++], 10);
  const height = parseInt(claimComponents[compIdx++], 10);

  for (let rows=0; rows < height; rows += 1 ) {
    let lineStart = ((yOffset + rows) * MAX_WIDTH) + xOffset;
    for (let cols=0; cols < width; cols += 1) {
      if (material[lineStart+cols]) {
        material[lineStart+cols] = 'X';
      } else {
        material[lineStart+cols] = id;
      }
    }
  }

  claims.push({
    raw, id, xOffset, yOffset, width, height
  });
}


function handleClose() {

  if (DEBUG) {
    for (let y=0; y < MAX_WIDTH; y += 1) {
      let line = '';
      for (let x=0; x < MAX_WIDTH; x += 1) {
        const val = material[(y*MAX_WIDTH)+x] 
        line += val ? val : '.';
        line += ' ';
      }
      console.log(line);
    }
  }


  const overlaps = material.reduce((prev, curr) => curr === 'X' ? prev + 1 : prev, 0);
  console.log(`Overlaps: ${overlaps}`);
  console.log(`Magic id: #${findValidClaim()}`);
};

function findValidClaim() {
  
  outer:for (let c=0; c < claims.length; c += 1) {
    const { id, xOffset, yOffset, width, height } = claims[c];

    for (let rows=0; rows < height; rows += 1 ) {
      let lineStart = ((yOffset + rows) * MAX_WIDTH) + xOffset;
      for (let cols=0; cols < width; cols += 1) {
        if (material[lineStart+cols] === 'X') {
          continue outer;
        }
      }
    }

    return id;
  }
}

getLineReader(handleLine, handleClose);