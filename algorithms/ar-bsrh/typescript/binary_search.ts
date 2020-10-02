function binarySearch(item_list, item) {
    let first = 0;
    let last = item_list.length - 1;
    let found = false;

    while (first <= last && !found) {
        let mid = Math.floor((first + last) / 2);
        if (item_list[mid] == item) {
            found = true;
        } else {
            if (item < item_list[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
    }

    return found;
}

console.log(binarySearch([1, 2, 3, 5, 8], 6));
console.log(binarySearch([1, 2, 3, 5, 8], 2));