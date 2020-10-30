/**
 * Longest increasing subsequence is the subsequence that has the longest streak of going up consecutively
 * @param {number[]} arr the sequence to search for longest subsequence
 */
function findLongestIncreasingSubsequence(arr) {
    let longestSubsequence = [];
    for (let arrKey in arr) {
        if (Number(arrKey) + 1 === arr.length) break; // stop before the last element
        let tempLength = 0; // holds the length of the subsequence which is increasing
        let isIncreasing = true;
        // if next element is greater than current element, subsequence is increasing
        while (isIncreasing = arr[Number(arrKey) + tempLength] < arr[(++tempLength) + Number(arrKey)]) continue;
        // when subsequence is no longer increasing, check if this subsequence is longer than any other previous one
        if (tempLength > longestSubsequence.length)
            longestSubsequence = arr.slice(Number(arrKey), tempLength + Number(arrKey));
    }
    return longestSubsequence;
}

function main() {
    let input = [
        3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6,
        4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9
    ];
    console.log(findLongestIncreasingSubsequence(input));
}

main();