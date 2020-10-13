//bubbleSort function
function bubbleSort (arr : number[]) {
    let len : number = arr.length;
    let swapped : boolean;
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
}

//Function to test bubbleSort
let main = () => {
	let arr = [7, 9, 5, 8, 2, 3, 1, 6, 4];
        bubbleSort(arr);
	return arr;
};

//Calling test function to display output
main();
