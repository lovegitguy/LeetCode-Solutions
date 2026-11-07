# 598. Range Addition II

## Problem

You are given an `m × n` matrix initialized with zeros and a list of operations.

Each operation `[a, b]` increments every element in the top-left `a × b` submatrix by 1.

Return the number of elements having the maximum value after performing all operations.

## Approach: Minimum Dimensions (Mathematical Observation)

Instead of actually creating and updating the matrix, we can solve the problem mathematically.

1. Initialize `minY = m` and `minX = n`.
2. Iterate through all operations.
3. For every operation `[a, b]`:
   - Update `minY = min(minY, a)`.
   - Update `minX = min(minX, b)`.
4. The overlapping region of all operations is the region that receives the maximum number of increments.
5. Its dimensions are `minY × minX`.
6. Return `minX * minY`.

### Why does this work?

Every operation starts from the top-left corner `(0, 0)`.

The cells that receive increments from every operation form a common overlapping rectangle.

The smallest height and width among all operations determine this rectangle.

Therefore:

`Maximum count = Minimum height × Minimum width`

If there are no operations, the entire matrix remains zero, so all `m × n` elements have the maximum value.

## Complexity Analysis

- **Time Complexity:** `O(k)` — We iterate through all `k` operations exactly once.
- **Space Complexity:** `O(1)` — We use only two additional integer variables.

## Key Learning

- Mathematical optimization instead of matrix simulation.
- Finding overlapping regions.
- Using minimum dimensions to determine the maximum-frequency region.
- Reducing unnecessary operations for better efficiency.

## C++ Concepts Used

- `vector<vector<int>>`
- Range-based for loop.
- `min()` function.
- Constant-space optimization.

