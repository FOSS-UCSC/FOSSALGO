function mergeSort(array) {
    const merge = function (array1, array2) {
        if (array1 == [] || array1 == undefined) {
            return array2;
        }
        else if (array2 == [] || array2 == undefined) {
            return array1;
        }
        else {
            let output = [];
            while (array1.length > 0 || array2.length > 0) {
                if (array1.length == 0) {
                    output.push(array2.shift());
                }
                else if (array2.length == 0) {
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
    };
    const n = array.length;
    if (n <= 1) {
        return array;
    }
    else {
        let part1 = array.splice(0, (n - n % 2) / 2);
        return merge(mergeSort(part1), mergeSort(array));
    }
}
