function doBinarySearch(arr, targetNum) {
  const len = arr.length
  let left = 0
  const right = len - 1
  let mid = Math.floor((right + left) / 2)

  while (arr[mid] < right) {
    if (targetNum < arr[mid]) {
      right = mid - 1 // search in the leftmost half of the array
    } else if (targetNum > arr[mid]) {
      left = mid + 1 // search in the right half of the array
    }
    mid = Math.floor((right + left) / 2) // recalculating mid value
  }
  return arr[mid] != targetNum ? -1 : mid
}

// doBinarySearch([3, 1, 4, 14, 78, 9, 36], 9)
