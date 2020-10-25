function linearSearch(array, key) {
  // Go through all the elements of an array to look for key.
  for (var i = 0; i < array.length; i++) {
    if (array[i] === key) {
      // key is Found
      return i;
    }
  }

  // key not found in the array.
  return -1;
}

// Created an array
const array = [1,6,8,12,25,36,43,97];
let result = linearSearch(array, 25);//key:25
