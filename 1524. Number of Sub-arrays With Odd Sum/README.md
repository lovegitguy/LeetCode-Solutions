# 1524. Number of Sub-arrays With Odd Sum

**Difficulty:** Medium  
**Topics:** Array, Prefix Sum, Counting, Math

## Problem

Given an array of integers `arr`, return the number of subarrays whose sum is odd.

Since the answer can be very large, return it modulo `10^9 + 7`.

## Approach: Prefix Sum + Parity Counting

### Intuition

Instead of calculating the sum of every possible subarray, we can use prefix sums and track how many previous prefix sums are even or odd.

The key mathematical observation is:

- Even + Even = Even
- Odd + Odd = Even
- Even + Odd = Odd

A subarray sum is calculated as:

`subarraySum = currentPrefixSum - previousPrefixSum`

Therefore, a subarray has an odd sum when the current and previous prefix sums have different parity.

### Variables Used

| Variable | Purpose |
|---|---|
| `MOD` | Prevents integer overflow by taking modulo \(10^9+7\). |
| `prefixSum` | Maintains the running prefix sum. |
| `oddCount` | Stores the number of subarrays with odd sums found so far. |
| `evenCount` | Counts previous even prefix sums. |
| `oddPrefix` | Counts previous odd prefix sums. |

**Important initialization:**

```cpp
int evenCount = 1;
int oddPrefix = 0;
```

We initialize `evenCount` to `1` because the empty prefix has a sum of zero, which is even.

This allows subarrays starting at index `0` to be counted correctly.

### Algorithm

1. Initialize `prefixSum = 0`.
2. Initialize `evenCount = 1` and `oddPrefix = 0`.
3. Traverse the array.
4. Add the current element to `prefixSum`.
5. Check the parity of the current prefix sum:

   **If the prefix sum is even:**
   - Previous odd prefix sums produce odd subarray sums.
   - Add `oddPrefix` to `oddCount`.
   - Increment `evenCount`.

   **If the prefix sum is odd:**
   - Previous even prefix sums produce odd subarray sums.
   - Add `evenCount` to `oddCount`.
   - Increment `oddPrefix`.

6. Apply modulo \(10^9+7\).
7. Return `oddCount`.

## C++ Solution

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long oddCount = 0;
        int prefixSum = 0;

        int evenCount = 1;
        int oddPrefix = 0;

        for(int num : arr) {
            prefixSum += num;

            if(prefixSum % 2 == 0) {
                oddCount = (oddCount + oddPrefix) % MOD;
                evenCount++;
            }
            else {
                oddCount = (oddCount + evenCount) % MOD;
                oddPrefix++;
            }
        }

        return oddCount;
    }
};
```

## Complexity Analysis

Let `n` be the length of the input array.

- **Time Complexity:** O(n) — We traverse the array exactly once.
- **Auxiliary Space Complexity:** O(1) — We maintain only a fixed number of variables.

## Key Learnings

- Understanding prefix sums.
- Using parity instead of calculating every subarray sum.
- Counting previous even and odd prefix sums.
- Understanding why the empty prefix must be counted.
- Applying modulo arithmetic.
- Optimizing a potential O(n²) subarray solution to O(n).

## Takeaway

The important insight is that we don't need to calculate every subarray sum.

By tracking the frequency of even and odd prefix sums, we can count all odd-sum subarrays in a single traversal.

This is a useful pattern for future prefix-sum and subarray-counting problems.