# 1752. Check if Array Is Sorted and Rotated

## Problem
Given an array `nums`, determine whether it was originally sorted in non-decreasing order and then rotated some number of positions.

Return `true` if the array satisfies this condition; otherwise, return `false`.

## Approach: Circular Traversal + Drop Counting

1. Initialize a variable `drops = 0` to count the number of times an element is greater than the element immediately following it.
2. Traverse the array using a `for` loop.
3. Compare the current element with the next element:
   - If `nums[i] > nums[(i+1) % nums.size()]`, increment `drops`.
4. Use the modulo operator `%` to handle circular traversal:
   - When `i` reaches the last index, `(i+1) % nums.size()` becomes `0`.
   - This compares the last element with the first element.
5. If `drops` is at most `1`, return `true`; otherwise, return `false`.

## Why Does This Work?

A sorted array can have at most one point where an element is greater than its next element after considering the array circularly.

For example:

`[3, 4, 5, 1, 2]`

Comparisons:
- `3 > 4` → No
- `4 > 5` → No
- `5 > 1` → Yes (one drop)
- `1 > 2` → No
- `2 > 3` → No (circular comparison)

Since there is exactly one drop, the array is sorted and rotated.

## C++ Concepts Used

- **Array Traversal:** Iterating through the vector using indices.
- **Modulo Operator (`%`):** Enables circular indexing.
- **Drop Counting:** Counting violations of non-decreasing order.
- **Boolean Return:** Returning whether the number of drops is at most one.

## Complexity Analysis

Let `n` be the size of the array.

- **Time Complexity:** O(n) — We traverse the array once.
- **Space Complexity:** O(1) — Only one integer variable is used.

## Key Learning

The modulo operator allows us to treat an array as circular without manually handling the last index.

Instead of checking every possible rotation, we can determine whether an array is sorted and rotated by counting its descending transitions.

