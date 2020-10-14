let insertionSort = (array) => {
  for (let outer = 1; outer < array.length; outer++) {
    for (let inner = 0; inner < outer; inner++) {
      if (array[outer] < array[inner]) {
        const [element] = array.splice(outer, 1);
        array.splice(inner, 0, element);
      }
    }
  }
  return array;
};

let main = () => {
	let arr = [9, 8, 7, 6, 5, 4 ,3 , 2, 1];
	insertionSort(arr);
	return arr;
};

main();
