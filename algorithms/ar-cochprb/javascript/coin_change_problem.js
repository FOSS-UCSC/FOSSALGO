
function waysofChange(s, numOfCoins, n) {

    if (n === 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    if (numOfCoins < 0 && n > 0) {
        return 0;
    }

    return waysofChange(s, numOfCoins, n - s[numOfCoins]) + waysofChange(s, numOfCoins - 1, n);
}

function main() {
    var s = [1, 2, 3];
    var n = 4;
    /* eslint-disable no-console */
    console.log(waysofChange(s, s.length - 1, n));
    /* eslint-enable no-console */
    
}

main();