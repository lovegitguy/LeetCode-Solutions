# 35. Search Insert Position

**Difficulty:** Easy  
**Topics:** Array, Binary Search  
**Language:** C++

## Problem Statement

Given a sorted array of distinct integers `nums` and an integer `target`, return the index if the target exists in the array.

If the target does not exist, return the index where it should be inserted to maintain sorted order.

**Problem Link:** https://leetcode.com/problems/search-insert-position/

## Approach: Binary Search

Since the array is sorted, Binary Search can efficiently find the target or determine its correct insertion position.

Maintain two pointers, `low` and `high`, to represent the current search range.

If the target is found, return its index.

If the target is not found, the final value of `low` represents the correct insertion position.

## Algorithm

1. Initialize `low = 0` and `high = nums.size() - 1`.
2. Run a loop while `low <= high`.
3. Calculate the middle index using:

   `mid = low + (high - low) / 2`

4. If `nums[mid] == target`, return `mid`.
5. If `nums[mid] < target`, search the right half by updating `low = mid + 1`.
6. Otherwise, search the left half by updating `high = mid - 1`.
7. If the target is not found, return `low`.

## C++ Solution

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return low;
    }
};
```

## Example

**Input:**

```text
nums = [1, 3, 5, 6]
target = 2
```

**Output:**

```text
1
```

**Explanation:**

- Initially, `low = 0` and `high = 3`.
- Middle index is `1`, where `nums[1] = 3`.
- Since `3 > 2`, move to the left half.
- Now `high = 0`.
- Middle index is `0`, where `nums[0] = 1`.
- Since `1 < 2`, update `low = 1`.
- The loop terminates because `low > high`.

The correct insertion position is index `1`.

## Complexity Analysis

**Time Complexity: O(log n)**

Binary Search eliminates half of the search space in every iteration.

**Auxiliary Space Complexity: O(1)**

Only a constant number of variables are used. No additional data structures are required.

## Key Learning

Binary Search can be used not only to find an element but also to determine its correct insertion position.

The important concept is that when the loop terminates, `low` points to the first position where the target can be inserted without disturbing the sorted order.

This handles insertion at the beginning, middle, and end of the array.