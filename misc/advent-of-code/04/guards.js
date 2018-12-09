const getLineReader = require("../input-reader");

const lineRegex = /^\[(\d+)-(\d+)-(\d+) (\d+):(\d+)\] (.+)/;
const guardRegex = /^Guard #(\d+)/;

const events = [];

// const EventTypes = {
//   SHIFT_START: 0,
//   FALLS_ASLEEP: 1,
//   WAKES_UP: 2
// }

function handleLine(line) {
  const matches = line.match(lineRegex);

  let matchIdx = 0;

  const raw = matches[matchIdx++];
  const year = parseInt(matches[matchIdx++], 10);
  const month = parseInt(matches[matchIdx++], 10);
  const day = parseInt(matches[matchIdx++], 10);
  const hour = parseInt(matches[matchIdx++], 10);
  const minute = parseInt(matches[matchIdx++], 10);
  const note = matches[matchIdx++];

  const calculatedTime = minute + (hour * 60) + (day * 60 * 24) + (month * 60 * 24 * 31);

  events.push({
    raw,
    year,
    month,
    day,
    hour,
    minute,
    note,
    calculatedTime
  });
}

function handleClose() {
  events.sort((a, b) => {
    if (a.calculatedTime < b.calculatedTime) {
      return -1;
    }
    if (a.calculatedTime > b.calculatedTime) {
      return 1;
    }

    return 0;
  });

  let index = 0;
  let maxTimeSlept = -1;
  let answer = 0;

  // let shifts = {};
  let guards = {};
  let sleepiestGuard;

  while (index < events.length) {
    const guardId = parseInt(events[index++].note.match(guardRegex)[1], 10);
    const timesSlept = [];
    let totalTimeSlept = 0;
    while (events[index] && events[index].note.startsWith("falls")) {
      const recId = index;
      const sleepMinute = events[index++].minute;
      const awakeMinute = events[index++].minute;
      const sleepTime = awakeMinute - sleepMinute;

      totalTimeSlept += sleepTime;

      timesSlept.push({
        id: recId,
        minute: sleepMinute,
        duration: sleepTime
      });
    }

    if (totalTimeSlept > 0) {
      if (guardId in guards) {
        guards[guardId].totalTimeSlept += totalTimeSlept;
        guards[guardId].timesSlept.push(...timesSlept);
      } else {
        guards[guardId] = {
          totalTimeSlept,
          timesSlept
        }
      }

      // shifts.push({
      //   guardId,
      //   eventStartId,
      //   totalTimeSlept,
      //   timesSlept
      // });

      if ( guards[guardId].totalTimeSlept > maxTimeSlept) {
        sleepiestGuard = guardId;
        maxTimeSlept = guards[guardId].totalTimeSlept;

        // console.log(`${sleepiestGuard} is now the sleepiest guard`);
      }
    }
  }



    

    // if (totalTimeSlept) {
    //   console.log(`Guard ${guardId} spent ${totalTimeSlept} minutes alseep on shift index ${eventStartId}`);
    // }

    // if (totalTimeSlept > maxTimeSlept) {
    //   // console.log(`Guard id: ${guardId} \nTotal Time Slept: ${totalTimeSlept}\nEvent Start Index: ${eventStartId}`);
    //   console.log(timesSlept);
    //   if (timesSlept.length > 1) {
    //     timesSlept.sort((a, b) => {
    //       if (a.duration < b.duration) return 1;
    //       if (a.duration > b.duration) return -1;
    //       return 0;
    //     })
    //   }
    //   answer = guardId * timesSlept[0].minute;
    //   maxTimeSlept = totalTimeSlept;
    // }
  // }

  Object.keys(guards).forEach(guardId => {
    console.log(`#${guardId} slept for ${guards[guardId].totalTimeSlept} minutes`);
  });


  console.log(`Sleepiest guard is ${sleepiestGuard}`);
  console.dir(guards[sleepiestGuard]);
  const sleepTimes = guards[sleepiestGuard].timesSlept;
  sleepTimes.sort((a, b) => {
    if (a.duration < b.duration) return 1;
    if (a.duration > b.duration) return -1;
    return 0;
  });
  // console.dir(sleepTimes);

  console.log(`The answer: ${sleepiestGuard * sleepTimes[0].minute}`);


  // shifts.sort((a, b) => {
  //   if (a.totalTimeSlept < b.totalTimeSlept) return 1;
  //   if (a.totalTimeSlept > b.totalTimeSlept) return -1;
  //   return 0;
  // });

  // shifts.forEach(({ totalTimeSlept, guardId, eventStartId}) => {
  //   console.log(`${totalTimeSlept}\t\t${guardId}\t\t${eventStartId}`);
  // })

  
  // events.forEach(e => console.log(e.raw));
}




getLineReader(handleLine, handleClose);