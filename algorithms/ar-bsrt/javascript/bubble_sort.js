// Bubble sort function
let bubbleSort = (arr) => {
    let len = arr.length, swapped;
    do {
        swapped = false;
        for (let i = 0; i < len; i++) {
            if (arr[i] > arr[i + 1]) {
                let tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
    return arr;
};

let main = () => {
	let arr = [9, 8, 7, 6, 5, 4 ,3 , 2, 1];
	bubbleSort(arr);
	return arr;
};

main();
