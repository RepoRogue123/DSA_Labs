# Matrix Diagonal Sum

## Problem Statement

You are given a matrix of size `n x n`. Your task is to write a function that calculates and prints the sum of the elements on both the left diagonal (primary diagonal) and the right diagonal (secondary diagonal) of the matrix.

### Input

1. The first line contains an integer `n`, where `n` is greater than 1 and less than 100, representing the size of the matrix.
2. The next `n` lines contain `n` integers each, representing the elements of the matrix.

### Output

- Print a single integer which is the sum of the left diagonal and right diagonal elements.

### Example Input

3<br>
1 2 3<br>
4 5 6<br>
7 8 9<br>


### Example Output

30


### Explanation

For the input matrix:

1 2 3<br>
4 5 6<br>
7 8 9<br>


- **Left Diagonal (Primary Diagonal)**: 1 + 5 + 9 = 15
- **Right Diagonal (Secondary Diagonal)**: 3 + 5 + 7 = 15
- **Total Sum**: 15 + 15 = 30

Hence, the output is `30`.

## Notes

- The function should efficiently handle the calculation by traversing the matrix only once.
- The matrix size `n` is constrained between 2 and 99, ensuring that the matrix is always square.
