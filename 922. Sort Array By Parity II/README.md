# 922. Sort Array By Parity II

## Problem
Given an array `nums` containing an equal number of even and odd integers, rearrange the elements so that every even index contains an even number and every odd index contains an odd number.

Return the rearranged array.

## Approach: Two Pointers (Index-Based Placement)

1. Initialize two pointers:
   - `even = 0` to track even indices.
   - `odd = 1` to track odd indices.
2. Traverse the array using a `while` loop as long as both pointers are within the array boundaries.
3. Check the element at the even index:
   - If it is even, move the `even` pointer forward by 2.
4. Otherwise, check the element at the odd index:
   - If it is odd, move the `odd` pointer forward by 2.
5. If both positions contain incorrectly placed elements:
   - Swap `nums[even]` and `nums[odd]`.
   - Move both pointers forward by 2.
6. Return the rearranged array.

## Why Does This Work?

The algorithm maintains two separate sequences of indices:

- Even indices: `0, 2, 4, 6...`
- Odd indices: `1, 3, 5, 7...`

Whenever an element is already in its correct parity position, its pointer moves forward by 2.

When both positions contain misplaced elements, swapping them fixes both positions simultaneously.

## C++ Concepts Used

- **Two Pointers:** Using two independent indices to track even and odd positions.
- **Modulo Operator (`%`):** Checking whether a number is even or odd.
- **`swap()`:** Exchanging two elements in a vector.
- **While Loop:** Continuing traversal until both pointers reach the array boundary.
- **In-Place Modification:** Rearranging the original vector without creating another vector.

## Complexity Analysis

Let `n` be the size of the array.

- **Time Complexity:** O(n) — Both pointers traverse their respective index sequences, processing each position at most once.
- **Space Complexity:** O(1) — Rearrangement happens directly inside the original vector.

## Key Learning

Two pointers do not always need to move one position at a time.

By incrementing each pointer by 2, we can independently traverse even and odd indices.

This technique is useful when a problem requires placing elements at specific index positions based on some condition.

