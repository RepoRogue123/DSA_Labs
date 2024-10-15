# Binary Conversion and Row Counting

## Problem Statement

Given an array of numbers, convert each number to its binary representation and store it as a matrix where each row holds a 32-bit binary number. The array of `n` numbers will generate an `n x 32` sized matrix. Return the count of rows that have at least 5 ones.

### Input Format

1. The first line contains an integer `N`, the size of the array.
2. The second line contains `N` space-separated integers.

### Output Format

- A single integer representing the count of rows with at least 5 ones.

### Sample Input

5<br>
63 62 61 89 90


### Sample Output

3


### Explanation

For the input `[63, 62, 61, 89, 90]`, the binary matrix is:

00000000000000000000000000111111<br>
00000000000000000000000000111110<br>
00000000000000000000000000111101<br>
00000000000000000000000001011001<br>
00000000000000000000000001011010<br>

