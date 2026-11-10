# 1464. Maximum Product of Two Elements in an Array

## Problem
Given an integer array `nums`, select two different indices `i` and `j`. Return the maximum value of:

\[
(nums[i]-1)\times(nums[j]-1)
\]

## Approach: Single Traversal (Two Maximums)

Instead of sorting the array or using nested loops, we can find the two largest elements in a single traversal.

### Logic

1. Initialize two variables:
   - `max1` = largest element.
   - `max2` = second-largest element.
2. Traverse the array.
3. If the current element is greater than `max1`:
   - Use `exchange(max1, n)` to update `max1` and store its previous value in `max2`.
4. Otherwise, if the current element is greater than `max2`, update `max2`.
5. Return `(max1 - 1) * (max2 - 1)`.

### C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;

        for (const int n : nums) {
            if (n > max1) {
                max2 = exchange(max1, n);
            }
            else if (n > max2) {
                max2 = n;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n) — We traverse the array exactly once.
- **Space Complexity:** O(1) — We use only two additional variables.

## Key Learning

- Tracking the largest and second-largest elements.
- Single-pass array traversal.
- Using `exchange()` from the C++ `<utility>` header.
- Avoiding sorting and nested loops when only the two largest elements are required.