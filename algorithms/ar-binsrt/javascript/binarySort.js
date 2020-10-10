function binarySort(item, sortedList, low = 0, high = sortedList.length - 1) {
  if (low === high) {
    // hit end of sortedList - done
    return item > sortedList[low] ? low + 1 : low
  }

  // get midpoint of list and item value
  let mid = low + Math.floor((high - low) / 2),
    itemCompare = sortedList[mid]

  if (item > itemCompare) {
    // work higher end of list
    return binarySort(item, sortedList, mid + 1, high)
  }

  if (item < itemCompare) {
    // work lower end of list
    return binarySort(item, sortedList, low, mid)
  }

  // found equal value - done
  return mid
}

// seed list of random ascending (sorted) numbers
let lastValue = 1,
  resultIndexList = [lastValue]

for (let i = 1; i < 10000; i++) {
  // generate a random higher number than prev one
  lastValue = Math.floor(Math.random() * 500) + lastValue
  resultIndexList.push(lastValue)
}

// insert values
let startTime = Date.now()

for (let i = 1; i < 1000; i++) {
  // generate a rand num and insert
  let nextValue = Math.floor(Math.random() * 2000000)

  resultIndexList.splice(binarySort(nextValue, resultIndexList), 0, nextValue)
}

console.log(`Duration: ${Date.now() - startTime}ms`)
