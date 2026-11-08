# LeetCode 73 – Set Matrix Zeroes

**Difficulty:** Medium  
**Topics:** Array, Matrix, Simulation

## Problem

Given an `m x n` integer matrix, if an element is `0`, set its entire row and column to `0`.

The modification must be performed in place.

## Approach: Two-Pass Matrix Traversal

I used two separate phases to solve this problem.

### 1. Identify Original Zeroes

I created two vectors:

- `ZeroRows`: Stores the row indices containing zeroes.
- `OneColumns`: Stores the column indices containing zeroes.

I traversed the entire matrix using nested loops.

Whenever I encountered `matrix[i][j] == 0`, I stored:
- `i` in `ZeroRows`.
- `j` in `OneColumns`.

### 2. Make Identified Rows Zero

I iterated through `ZeroRows`.

For every stored row index, I traversed all its columns and assigned zero to every element.

### 3. Make Identified Columns Zero

I iterated through `OneColumns`.

For every stored column index, I traversed all rows and assigned zero to the corresponding elements.

## C++ Concepts Learned

- Traversing a 2D vector using nested loops.
- Storing indices in separate 1D vectors.
- Using `push_back()` to store row and column indices.
- Range-based for loops.
- Modifying a 2D vector through row and column indices.
- Separating data collection from matrix modification.

## Complexity Analysis

Let `m` represent the number of rows and `n` represent the number of columns.

**Time Complexity:** `O(m × n)`

- Scanning the matrix: `O(m × n)`.
- Processing stored rows: At most `O(m × n)`.
- Processing stored columns: At most `O(m × n)`.

Overall: `O(m × n)`.

**Space Complexity:** `O(m × n)` in the worst case because the two vectors can store up to `m × n` indices combined.

## Key Learning

The most important lesson was separating the discovery of original zeroes from modifying the matrix.

If I modify the matrix while scanning it, newly created zeroes can be mistaken for original zeroes.

Using two separate vectors prevents this logical problem.

## Future Optimization

This approach can be optimized to use `O(1)` auxiliary space by using the first row and first column of the matrix as markers. This optimization is a separate learning step.