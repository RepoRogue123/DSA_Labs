# Grid Filling with Boxes

This document describes a function `grid(n)` that calculates the total number of ways to fill a grid of size 4 x N with boxes of size 1 x 4 and 4 x 1.

## Problem Statement

Given a grid of size 4 x N, where N is a positive integer, you are provided with boxes of two sizes:

- 1 x 4 (single row, four columns)
- 4 x 1 (four rows, single column)

The task is to write a function `grid(n)` that determines the total number of valid arrangements to fill the entire grid using these boxes.

## Input Format

The input consists of a single line containing an integer `n` representing the number of columns in the grid (N > 0).

## Output Format

The function should return a single integer value representing the total number of valid filling arrangements.

## Constraints

- N is always greater than 0.

## Sample Test Case

**Input:**<br>
4


**Output:**<br>
2