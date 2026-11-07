# 463. Island Perimeter

## Problem
You are given a 2D grid where:
- `1` represents land.
- `0` represents water.

Calculate the perimeter of the island. The island is surrounded by water and contains exactly one island.

## Approach: Counting Land Cells and Shared Edges

1. Initialize `perimeter = 0`.
2. Traverse the entire grid using nested loops.
3. Whenever a land cell (`grid[i][j] == 1`) is found, add `4` to the perimeter.
4. Check the right neighbour:
   - If it exists and is also land, subtract `2`.
5. Check the bottom neighbour:
   - If it exists and is also land, subtract `2`.
6. Return the final perimeter.

### Why subtract 2?

Every land cell initially contributes four sides. When two land cells share an edge, that edge is counted twice, once for each cell.

Therefore, we subtract `2` for every shared edge.

We only check the right and bottom neighbours to avoid counting shared edges twice.

## Complexity Analysis

- **Time Complexity:** `O(m × n)` — We traverse every cell exactly once.
- **Space Complexity:** `O(1)` — We use only a constant amount of extra space.

## Key Learning

- 2D matrix traversal using nested loops.
- Boundary checking to prevent out-of-bounds access.
- Neighbour traversal (right and bottom).
- Avoiding double-counting shared edges.
