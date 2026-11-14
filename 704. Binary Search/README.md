# 704. Binary Search

**Difficulty:** Easy  
**Topics:** Array, Binary Search  
**Language:** C++

## Problem Statement

Given an array of integers `nums` sorted in ascending order and an integer `target`, return the index of `target` if it exists in the array.

If the target does not exist, return `-1`.

**Problem Link:** https://leetcode.com/problems/binary-search/

## Approach: Iterative Binary Search

Since the array is sorted, Binary Search can efficiently find the target by repeatedly dividing the search space into two halves.

Maintain two pointers, `low` and `high`, representing the current search range.

Calculate the middle index and compare its element with the target. Depending on the comparison, eliminate the half that cannot contain the target.

## Algorithm

1. Initialize `low = 0` and `high = nums.size() - 1`.
2. Run a loop while `low <= high`.
3. Calculate the middle index using:

   `mid = low + (high - low) / 2`

4. If `nums[mid] == target`, return `mid`.
5. If `nums[mid] < target`, search the right half by updating `low = mid + 1`.
6. Otherwise, search the left half by updating `high = mid - 1`.
7. If the loop terminates without finding the target, return `-1`.

## C++ Solution

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
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

        return -1;
    }
};
```

## Example

**Input:**

```text
nums = [-1, 0, 3, 5, 9, 12]
target = 9
```

**Output:**

```text
4
```

**Explanation:**

- Initially, `low = 0` and `high = 5`.
- Middle index is `2`, where `nums[2] = 3`.
- Since `3 < 9`, search the right half.
- Next, middle index is `4`, where `nums[4] = 9`.
- The target is found at index `4`.

## Complexity Analysis

**Time Complexity: O(log n)**

The search space is divided into half during every iteration. Therefore, the number of iterations grows logarithmically with the array size.

**Auxiliary Space Complexity: O(1)**

The algorithm uses only a constant number of variables and does not require additional data structures.

## Key Learning

Binary Search is an efficient searching technique for sorted arrays.

The main idea is to eliminate half of the search space in every iteration instead of checking every element individually.

Using `low + (high - low) / 2` also avoids potential integer overflow associated with `(low + high) / 2`.