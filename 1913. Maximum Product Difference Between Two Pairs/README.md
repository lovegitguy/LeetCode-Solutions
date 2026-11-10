# 1913. Maximum Product Difference Between Two Pairs

## Problem

Given an integer array `nums`, choose four distinct indices `a`, `b`, `c`, and `d`.

Return the maximum possible product difference:

\[
(nums[a]\times nums[b])-(nums[c]\times nums[d])
\]

## Approach: Sorting + Greedy

We can maximize the difference by:
- Multiplying the two largest elements to get the maximum product.
- Multiplying the two smallest elements to get the minimum product.

Sorting makes it easy to identify these elements.

### Logic

1. Sort the array in ascending order.
2. Multiply the last two elements to calculate the maximum product.
3. Multiply the first two elements to calculate the minimum product.
4. Subtract the minimum product from the maximum product.
5. Return the result.

### C++ Solution

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int productMinimum = 0;
        int productMaximum = 0;
        int productdifference = 0;

        sort(nums.begin(), nums.end());

        productMaximum = nums[nums.size()-1] * nums[nums.size()-2];

        productMinimum = nums[0] * nums[1];

        productdifference = productMaximum - productMinimum;

        return productdifference;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n log n) — Sorting the array takes O(n log n).
- **Space Complexity:** O(1) auxiliary space, excluding the sorting implementation's internal stack space.

## Key Learnings

- Using sorting to identify the two largest and two smallest elements.
- Accessing array elements using `nums[0]`, `nums[1]`, and `nums.size()`.
- Applying a greedy strategy to maximize a mathematical expression.
- Avoiding unnecessary loops when direct indexing is sufficient.
- Calculating maximum and minimum products independently.