# 167. Two Sum II - Input Array Is Sorted

## Problem
Given a **1-indexed array of integers `numbers` sorted in non-decreasing order**, find two numbers such that they add up to a given `target`.

Return the indices of these two numbers as `[index1, index2]`, where `index1 < index2`.

The solution must use constant extra space.

## Approach: Two Pointers

1. Initialize two pointers:
   - `left = 0` pointing to the first element.
   - `right = numbers.size() - 1` pointing to the last element.
2. Run a `while` loop as long as `left < right`.
3. Calculate the sum of the elements at both pointers:
   - `sum = numbers[left] + numbers[right]`
4. Check the sum:
   - If `sum == target`, return `{left + 1, right + 1}`.
   - If `sum > target`, decrement `right` to get a smaller sum.
   - If `sum < target`, increment `left` to get a larger sum.
5. If no valid pair is found, return an empty vector.

## Why Does This Work?

The array is already sorted in non-decreasing order, which allows us to make decisions without checking every possible pair.

- **Sum too large:** Move the right pointer left because smaller values are available.
- **Sum too small:** Move the left pointer right because larger values are available.
- **Sum matches:** We have found the required pair.

This eliminates the need for nested loops.

## Example

Input:
`numbers = [2, 7, 11, 15]`

`target = 9`

| Left | Right | Sum | Action |
|---|---|---|---|
| 2 | 15 | 17 | Move right |
| 2 | 11 | 13 | Move right |
| 2 | 7 | 9 | Found pair |

Output: `[1, 2]`

**Note:** The problem uses 1-based indexing, so we return `left + 1` and `right + 1` instead of the original 0-based indices.

## C++ Concepts Used

- **Two Pointers:** Maintaining pointers at opposite ends of a sorted array.
- **While Loop:** Repeating comparisons until the pointers meet.
- **Sorted Array Property:** Using the order of elements to decide pointer movement.
- **Vector Return:** Returning the two required indices using an initializer list.
- **Constant Extra Space:** Modifying only pointer variables without creating another data structure.

## Complexity Analysis

Let `n` be the size of the input array.

- **Time Complexity:** O(n) — Each pointer moves toward the other at most `n` times.
- **Space Complexity:** O(1) — Only two pointer variables and a sum variable are used.

## Key Learning

The Two Pointers technique becomes especially powerful when an array is sorted.

Instead of checking every possible pair using nested loops (O(n²)), we use the sorted property to eliminate unnecessary comparisons and solve the problem in O(n).

**Important:** This approach relies on the input array being sorted. It should not be directly applied to an unsorted array.

