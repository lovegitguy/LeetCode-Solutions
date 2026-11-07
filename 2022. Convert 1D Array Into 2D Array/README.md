# 2022. Convert 1D Array Into 2D Array

## Problem

You are given:
- A 1D integer array called `original`.
- Two integers `m` and `n`, representing the required number of rows and columns.

Convert the 1D array into a 2D array with `m` rows and `n` columns.

The elements must maintain their original order.

If the number of elements in `original` is not equal to `m × n`, return an empty 2D array.

## Approach: 1D to 2D Index Mapping

Instead of manually inserting elements row by row, we use mathematical index mapping.

### Steps

1. Check whether the size of the original array equals `m * n`.
2. If the sizes do not match, return an empty 2D vector.
3. Create a 2D result matrix:

   `vector<vector<int>> ans(m, vector<int>(n));`

4. Traverse the original array using a single loop.
5. Convert each 1D index `i` into its corresponding 2D coordinates:

   - Row index: `i / n`
   - Column index: `i % n`

6. Place each element into the corresponding position:

   `ans[i / n][i % n] = original[i];`

7. Return the resulting 2D array.

## Understanding the Index Mapping

Consider:

```cpp
original = {1, 2, 3, 4, 5, 6};
m = 2;
n = 3;
```

The resulting matrix is:

```text
1 2 3
4 5 6
```

The index mapping works as follows:

| 1D Index | Row (i / n) | Column (i % n) |
|---|---|---|
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 2 | 0 | 2 |
| 3 | 1 | 0 |
| 4 | 1 | 1 |
| 5 | 1 | 2 |

This ensures that all elements retain their original order.

## Complexity Analysis

**Time Complexity: O(m × n)**

- Creating the result matrix takes `O(m × n)` time.
- Filling the matrix requires traversing all elements once.

**Space Complexity: O(m × n)**

- We create a new 2D matrix containing `m × n` elements.

## C++ Concepts Used

- 1D vectors: `vector<int>`
- 2D vectors: `vector<vector<int>>`
- Index mapping.
- Integer division (`/`).
- Modulo operator (`%`).
- Matrix initialization.
- Conditional validation.

## Key Learning

This problem demonstrates how to convert a linear array into a 2D matrix while preserving element order.

The important formulas are:

- `row = i / n`
- `column = i % n`

