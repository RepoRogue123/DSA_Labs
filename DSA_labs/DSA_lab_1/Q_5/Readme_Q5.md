

# Set Exclusive-Or (Symmetric Difference) of Two Arrays

This program takes two arrays of equal size as input and outputs their **set exclusive-or**. The set exclusive-or of two arrays is the sorted array of unique elements that are present in only one of the arrays.

## Problem Statement

Given two arrays of integers with equal size, find the **set exclusive-or** of the two arrays, i.e., the unique values that appear in only one of the arrays, not both. The result should be displayed as a sorted 1D array.

### Input Format
1. The first line contains an integer `N`, the size of the arrays.
2. The second line contains `N` space-separated integers representing the first array.
3. The third line contains `N` space-separated integers representing the second array.

### Output Format
- A single line containing the space-separated integers representing the **symmetric difference** (set-exclusive or) of the two arrays. The integers should be sorted in ascending order.

### Constraints
- The two arrays have the same size `N`.

## Example

### Sample Input
```
4
1 2 3 4
2 3 4 5
```

### Sample Output
```
1 5
```

