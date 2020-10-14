function merge(array1, array2) {
    if (array1 === []) {
        return array2;
    }
    else if (array2 === []) {
        return array1;
    }
    else {
        let output = [];
        while (array1.length > 0 || array2.length > 0) {
            if (array1.length === 0) {
                output.push(array2.shift());
            }
            else if (array2.length === 0) {
                output.push(array1.shift());
            }
            else if (array1[0] < array2[0]) {
                output.push(array1.shift());
            }
            else {
                output.push(array2.shift());
            }
        }
        return output;
    }
}
function mergeSort(array) {
    const n = array.length;
    if (n <= 1) {
        return array;
    }
    else {
        let part1 = array.splice(0, Math.trunc(n / 2));
        return merge(mergeSort(part1), mergeSort(array));
    }
}
