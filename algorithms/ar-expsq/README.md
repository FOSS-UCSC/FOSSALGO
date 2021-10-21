# Exponentiation by squaring

## Introduction
Exponentiation by squaring is a method/algorithm used for faster computation of larger integer powers of a number.
This algorithm generally finds application in cryptography.

The very basic idea behind this is to reduce the number of multiplications(or steps) performed.

For eg consider the following examples (using '^' for denoting power or exponentiation)
```
x ^ 15 is normally calculated as x * x * x * x...x * x * x(15 times)
(which means 15 steps/multiplications in total)

Exponentiation by squaring attempts to bring down the number of multiplications required by using the following
property of exponents (law of products)
x ^ (a + b) = x ^ a * x ^ b

Thus the above example of x ^ 15 can be broken down as sum of smaller powers eg x ^ 15 = x ^ 14 * x ^ 1,
or x ^ 15 = x ^ 13 * x ^ 2 and so on

We can then calculate x ^ 15 as follows:
x * x = x ^ 2
x * x ^ 2 = x ^ 3  -- (1)
x ^ 3 * x ^ 3 = x ^ 6
x ^ 6 * x ^ 6 = x ^ 12
x ^ 12 * x ^ 3 = x ^ 15
(We calculated x ^ 15 in total five steps or five multiplications which is faster than 15)

Similarly for x ^ 16 (which is a power of two)
x ^ 16 is normally calculated as x * x ...x * x * x(16 times)

Using the property mentioned above we can calculate
x * x = x ^ 2
x ^ 2 * x ^ 2 = x ^ 4
x ^ 4 * x ^ 4 = x ^ 8
x ^ 8 * x ^ 8 = x ^ 16
(We calculated this in 4 steps/multiplications instead of 16)

There are two things to consider here:
1. While we break down powers it's ideal to break them into sums of powers of two since they are easier to calculate (we just keep squaring)
2. If we look at (1) from above we see that we have to do an additional multiplication with x when the power is odd

This helps us in developing the pseudocode by using the below formula:
```
![image](https://user-images.githubusercontent.com/74228962/138101858-aa85ba96-273c-4e12-a059-ac3b5089ed05.png)

```
(source: Wikipedia)

Pseudocode (recursive)
function exponentiation_by_square(x, n):
  if x == 0 return 1
  if x == 1 return x
  else if x is even return exponetiaion_by_square(x * x, n / 2)
  else if x is odd return x * exponentiation_by_square(x * x, (n - 1) / 2)

Pseudocode (iterative)
function exponentiation_by_square(x, n):
  result = 1
  while n > 0
    if n is odd result = result * x
    else x = x * x
    n = n / 2
  return result

(Note that exponentiation by squaring is same as binary exponentiation)
  
```
[Learn more about Exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)

## Implementations

Below are some examples of how this is implemented using different programming languages.
-   [C](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/c/exponentiation_by_squaring.c)
-   [Go](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/golang/exponentiation_by_square.go)
-   [Java](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/java/ExponentiationBySquaring.java)
-   [JavaScript](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/javascript/exponentiation_by_squaring.js)
-   [Python 2](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/python2/exponentiation_by_squaring.py)
-   [Python 3](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/python3/exponentiation_by_squaring.py)
-   [TypeScript](https://github.com/tanvimoharir/FOSSALGO/blob/master/algorithms/ar-expsq/typescript/exp_by_squaring.ts)
