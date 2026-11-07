# 1260. Shift 2D Grid

## Problem

You are given an `m × n` 2D grid and an integer `k`.

You need to shift the grid `k` times.

During each shift:
1. Every element moves one position to the right.
2. The last element of each row moves to the first position of the next row.
3. The last element of the entire grid moves to the first position of the first row.

Return the resulting 2D grid after performing all shifts.

## Approach: Index Mapping + Modular Arithmetic

Instead of shifting the elements one by one, we convert the 2D matrix positions into a single linear index.

### Steps

1. Calculate the number of rows (`m`) and columns (`n`).
2. Calculate the total number of elements:

   `total = m * n`

3. Reduce the number of shifts using:

   `k %= total`

   This is because shifting the grid by its total number of elements brings it back to its original configuration.

4. If `k == 0`, return the original grid.
5. Create a new result matrix of the same dimensions.
6. Traverse every element in the original grid.
7. Convert its 2D position `(r, c)` into a 1D index:

   `index = r * n + c`

8. Calculate its new position after shifting:

   `newIndex = (r * n + c + k) % total`

9. Convert the new 1D index back into 2D coordinates:

   - `newR = newIndex / n`
   - `newC = newIndex % n`

10. Place the original element into its new position:

    `result[newR][newC] = grid[r][c]`

11. Return the result matrix.

## Why Does This Work?

A 2D matrix can be viewed as a single continuous 1D array by reading elements row by row.

For example:

```text
1 2 3
4 5 6
```

Can be represented as:

```text
1 2 3 4 5 6
```

After shifting right by 2 positions:

```text
5 6 1 2 3 4
```

We use modulo (`%`) to handle elements that move beyond the last position.

This allows us to calculate every element's destination directly without performing individual shifts.

## Complexity Analysis

Let `m` represent the number of rows and `n` represent the number of columns.

**Time Complexity: O(m × n)**

- We traverse every element exactly once.
- Each element's new position is calculated in constant time.

**Space Complexity: O(m × n)**

- We create a separate result matrix containing `m × n` elements.

## C++ Concepts Used

- 2D vectors: `vector<vector<int>>`
- Linear indexing.
- Index conversion between 1D and 2D arrays.
- Modular arithmetic (`%`).
- Integer division (`/`).
- Matrix traversal.

## Key Learning

This problem demonstrates how a 2D matrix can be transformed into a linear 1D representation to simplify operations.

The most important concept is **mapping between 2D coordinates and 1D indices**.

This technique is useful in matrix manipulation, grid transformations, cyclic rotations and array-based simulations.

