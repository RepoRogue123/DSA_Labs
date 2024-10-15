

# Matrix Column Sum of Transpose

Welcome to the **Matrix Column Sum of Transpose** repository! This project focuses on computing the sum of each column of the transpose of a given matrix. The input matrix is of size `r x c`, and the output is a single line of space-separated integers representing the sums of each column of the transpose.

## Problem Statement

Given an `r x c` matrix, compute the sum of each column of its transpose without using any external libraries other than `iostream`.

### Input Format

- First line: Two integers, `r` (number of rows) and `c` (number of columns).
- Next `r` lines: Each containing `c` integers representing the elements of the matrix.

### Output Format

- A single line with space-separated integers representing the sums of each column of the transpose of the matrix.

### Constraints

- `1 <= r, c <= 100`
- `-1000 <= matrix elements <= 1000`

### Example

#### Input:
```
2 3
1 2 3
4 5 6
```

#### Output:
```
6 15
```

### Explanation

The transpose of the matrix:
```
1 4
2 5
3 6
```
The sum of columns of the transpose:
- 1 + 2 + 3 = 6
- 4 + 5 + 6 = 15

Thus, the output is `6 15`.

## How to Run

1. Clone this repository to your local machine.
2. Navigate to the directory containing the source code.
3. Compile the code using a C++ compiler, e.g., `g++ -o matrix_sum matrix_sum.cpp`.
4. Run the executable, and input the matrix dimensions and elements as prompted.

## Code Structure

- **matrix_sum.cpp**: The main C++ code file containing the logic to compute the column-wise sum of the transpose.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

