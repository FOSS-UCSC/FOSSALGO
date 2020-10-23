function largestSumContiguousSubarray (arr: number[]) {
    let globalMax = Number.MIN_VALUE;
    let localMax = 0;

    for (const num of arr) {
        localMax += num;

        if (globalMax < localMax) {
            globalMax = localMax;
        }
        if (localMax < 0) {
            localMax = 0;
        }
    }

    return globalMax;
}

function main () {
    let input = [2, 3, 0, 4];
    largestSumContiguousSubarray(input);
}

main();
