function primeFactors(num) {
    var number = num
    if (number < 1)
        return;
    for (let counter = 2;
        (counter * counter) <= number; counter++) {
        while (number % counter == 0) {
            console.log(counter);
            number = number / counter;
        }
    }
    if (number > 0) {
        console.log(number);
    }
}

primeFactors(40)