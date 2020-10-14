function merge(array1: number[], array2: number[]) : number[] {
    let output : number [] = [];
    while (array1.length > 0 || array2.length > 0) {
        if (array2.length === 0 || array1[0] < array2[0]) {
            output.push(array1.shift());
        }
        else {
            output.push(array2.shift());
        }
    }
    return output;
}
function mergeSort(array: number[]) : number[]{
    const n : number = array.length;
    if (n <= 1) {
        return array;
    }
    else {
        let part1 = array.splice(0,  (n-(n%2))/2);
        return merge(mergeSort(part1), mergeSort(array));
    }
}

mergeSort([7,2,9,66,54]); //Expected output: [2,7,9,54,66]