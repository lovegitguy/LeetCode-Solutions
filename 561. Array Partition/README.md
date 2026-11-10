# 561. Array Partition

## Problem

Given an integer array `nums` containing `2n` elements, divide it into `n` pairs such that the sum of the minimum element from each pair is maximized.

## Approach: Sorting + Greedy

The key observation is that we should pair adjacent elements after sorting the array.

### Logic

1. Sort the array in ascending order.
2. Pair adjacent elements:
   - `(nums[0], nums[1])`
   - `(nums[2], nums[3])`
   - `(nums[4], nums[5])`
3. Since the array is sorted, the first element of every pair is its minimum.
4. Add every element at an even index to the sum.
5. Return the final sum.

### C++ Solution

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n log n) — Sorting the array takes O(n log n), followed by a linear traversal.
- **Space Complexity:** O(1) auxiliary space, excluding the sorting implementation's internal stack space.

## Key Learnings

- Sorting can simplify pairing problems.
- Greedy strategy: make locally optimal pairings to maximize the overall result.
- Using `i += 2` to traverse alternate indices.
- After sorting, the smaller element of each adjacent pair is at the even index.