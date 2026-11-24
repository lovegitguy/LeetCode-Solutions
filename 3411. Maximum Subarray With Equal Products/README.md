# LeetCode 3411: Maximum Subarray With Equal Products

## Problem

Given an integer array `nums`, find the maximum length of a non-empty subarray such that:

\[
\text{Product} = \text{LCM} \times \text{GCD}
\]

Return the maximum length.

## Approach

We use two pointers, `left` and `right`, to examine subarrays ending at each position.

For every `right` index:

1. Initialize:
   - `prod = 1` to store the product.
   - `l = 1` to store the LCM.
   - `g = 0` to store the GCD.
2. Traverse the current subarray from `left` to `right`.
3. Update:
   - Product using multiplication.
   - GCD using `gcd()`.
   - LCM using `lcm()`.
4. If the condition `prod > l * g` is true, move `left` forward and recalculate the values.
5. If `prod == l * g`, update the maximum length.

The process continues until every possible right endpoint has been considered.

## Key Concepts

### GCD (Greatest Common Divisor)

The largest integer that divides two or more numbers without leaving a remainder.

C++ provides `gcd()` through the `<numeric>` header.

### LCM (Least Common Multiple)

The smallest positive integer divisible by two or more numbers.

C++ provides `lcm()` through the `<numeric>` header.

### Two Pointers

- `left` represents the starting index of the current subarray.
- `right` represents the ending index.
- Moving `left` forward shrinks the current subarray.

## C++ Solution

```cpp
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0, ans = 0;

        for (int right = 0; right < n; ++right) {
            long long prod = 1, l = 1;
            int g = 0;

            for (int i = left; i <= right; ++i) {
                prod *= nums[i];
                g = (g == 0) ? nums[i] : gcd(g, nums[i]);
                l = lcm(l, static_cast<long long>(nums[i]));
            }

            while (left <= right && prod > 1LL * l * g) {
                ++left;
                prod = 1;
                l = 1;
                g = 0;

                for (int i = left; i <= right; ++i) {
                    prod *= nums[i];
                    g = (g == 0) ? nums[i] : gcd(g, nums[i]);
                    l = lcm(l, static_cast<long long>(nums[i]));
                }
            }

            if (left <= right && prod == 1LL * l * g) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};
```

## Example

**Input:**
```text
nums = [1, 2, 1, 2, 1, 1, 1]
```

**Output:**
```text
5
```

**Explanation:**

The subarray `[1, 2, 1, 2, 1]` has:

- Product = 4
- GCD = 1
- LCM = 2

Therefore:

\[
4 = 2 \times 1
\]

Its length is 5.

## Complexity Analysis

Let `n` be the size of the array.

- **Time Complexity:** The implementation repeatedly traverses the current window to recalculate product, GCD, and LCM. In the worst case, this takes \(O(n^2)\).
- **Auxiliary Space Complexity:** \(O(1)\), excluding the input array.

**Note:** This implementation assumes intermediate product and LCM values fit in `long long`.
