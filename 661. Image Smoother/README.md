# 661. Image Smoother

## Problem

You are given an `m × n` integer matrix representing an image.

Each cell represents the intensity of a pixel.

For every cell, calculate the average of:
- The cell itself.
- All its valid neighbouring cells, including diagonal neighbours.

Return a new matrix containing the smoothed pixel values.

Integer division is used, so decimal values are discarded.

## Approach: 3×3 Neighbourhood Traversal

Instead of manually checking all eight directions, we use nested loops to examine the 3×3 neighbourhood around every cell.

### Steps

1. Get the number of rows (`m`) and columns (`n`).
2. Create a new `result` matrix of the same dimensions, initialized with zeros.
3. Traverse the original matrix using two nested loops.
4. For every cell `(i, j)`:
   - Initialize `sum = 0`.
   - Initialize `count = 0`.
5. Use two additional nested loops to visit the surrounding 3×3 neighbourhood:
   - Rows from `i - 1` to `i + 1`.
   - Columns from `j - 1` to `j + 1`.
6. Check whether each neighbouring position is within matrix boundaries:
   - `r >= 0`
   - `r < m`
   - `c >= 0`
   - `c < n`
7. If valid, add its value to `sum` and increment `count`.
8. Calculate the average using integer division:

   `result[i][j] = sum / count`

9. Return the resulting matrix.

## Why Use a Separate Result Matrix?

We must calculate every average using the original image values.

If we modified the original matrix directly, previously smoothed values could affect calculations for subsequent cells.

Using a separate matrix prevents this problem.

## Complexity Analysis

Let:
- `m` = number of rows.
- `n` = number of columns.

**Time Complexity:** `O(m × n)`

We visit every matrix cell and examine at most 9 positions around it. Since 9 is constant, the overall complexity is `O(m × n)`.

**Space Complexity:** `O(m × n)`

We create a separate result matrix containing `m × n` elements.

## C++ Concepts Used

- 2D vectors: `vector<vector<int>>`
- Nested loops.
- Neighbourhood traversal.
- Boundary checking.
- Integer division.
- Separate matrix creation.

## Key Learning

This problem introduces an important matrix technique: **examining neighbouring cells using nested loops and boundary conditions.**

The same technique is useful in:
- Grid-based problems.
- Image processing.
- Flood Fill.
- Island and connected-component problems.
- Matrix-based simulations.

**LeetCode:** [661. Image Smoother](https://leetcode.com/problems/image-smoother/)

**Language:** C++