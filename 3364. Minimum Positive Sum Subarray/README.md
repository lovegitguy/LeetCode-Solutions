# 3364. Minimum Positive Sum Subarray

**Difficulty:** Easy  
**Topics:** Array, Subarray, Brute Force  
**Language:** C++

## Problem Statement

Given an integer array `nums` and two integers `l` and `r`, find the minimum sum of a subarray whose length is between `l` and `r` (inclusive) and whose sum is positive.

Return the minimum positive sum. If no valid subarray exists, return `-1`.

**Problem Link:** https://leetcode.com/problems/minimum-positive-sum-subarray/

## Approach: Brute Force Using Nested Loops

Generate all possible contiguous subarrays using two nested loops.

The outer loop selects the starting index, while the inner loop extends the subarray by selecting different ending indices.

Maintain a running sum (`current_sum`) to calculate the sum of each subarray without repeatedly traversing its elements.

For every subarray, calculate its length and check whether it satisfies the given constraints.

## Algorithm

1. Initialize `min_sum = INT_MAX`.
2. Traverse the array using an outer loop to select the starting index `i`.
3. Initialize `current_sum = 0` for every new starting index.
4. Use an inner loop with `j` to extend the subarray.
5. Add `nums[j]` to `current_sum`.
6. Calculate the subarray length using:

   `len = j - i + 1`

7. If `len > r`, break because the maximum allowed length has been exceeded.
8. If `len >= l` and `current_sum > 0`, update `min_sum` using `min()`.
9. After checking all possible subarrays, return `-1` if `min_sum` remains `INT_MAX`; otherwise, return `min_sum`.

## C++ Solution

```cpp
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;

        for (int i = 0; i < n; i++) {
            int current_sum = 0;

            for (int j = i; j < n; j++) {
                current_sum += nums[j];

                int len = j - i + 1;

                if (len > r) break;

                if (len >= l && current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                }
            }
        }

        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
```

## Example

**Input:**

```text
nums = [3, -2, 1, 4]
l = 2
r = 3
```

**Output:**

```text
1
```

**Explanation:**

Consider the valid subarrays:

- `[3, -2]` → Sum = 1
- `[3, -2, 1]` → Sum = 2
- `[-2, 1]` → Sum = -1
- `[-2, 1, 4]` → Sum = 3
- `[1, 4]` → Sum = 5

The minimum positive sum is `1`, obtained from the subarray `[3, -2]`.

## Complexity Analysis

**Time Complexity: O(n × min(n, r))**

For every starting index, the inner loop examines at most `r` elements, subject to the remaining array length.

In the worst case, this becomes O(n × r).

**Auxiliary Space Complexity: O(1)**

Only a constant number of variables are used. No additional arrays or data structures are created.

## Key Learning

Nested loops can be used to generate all possible contiguous subarrays.

Maintaining a running sum allows us to calculate each extended subarray's sum efficiently.

The expression `j - i + 1` calculates the length of a subarray, while `break` prevents unnecessary iterations once the maximum allowed length is exceeded.