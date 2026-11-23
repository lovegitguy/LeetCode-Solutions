# LeetCode 674: Longest Continuous Increasing Subsequence

## Problem

Given an integer array `nums`, return the length of the longest continuous strictly increasing subarray.

A continuous increasing subarray is a subarray where every element is strictly greater than the previous element.

**Example:**

Input:
```text
nums = [1,3,5,4,7]
```

Output:
```text
3
```

Explanation:

The longest continuous increasing subarray is `[1,3,5]`, which has a length of `3`.

## Approach

### Tracking Current Length and Maximum Length

We use two variables:

- `currentLen`: Tracks the length of the current continuous increasing subsequence.
- `maxlen`: Stores the maximum increasing subsequence length found so far.

**Steps:**

1. Initialize `currentLen = 1` and `maxlen = 1`, since a single element is itself an increasing subsequence.
2. Handle the empty array separately by returning `0`.
3. Start traversing the array from index `1`, comparing each element with its previous element.
4. If `nums[i] > nums[i-1]`:
   - Increment `currentLen`.
   - Update `maxlen` using `max(maxlen, currentLen)`.
5. Otherwise:
   - Reset `currentLen` to `1`, because the increasing sequence has been broken.
6. Return `maxlen`.

## C++ Solution

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currentLen = 1;
        int maxlen = 1;

        if(nums.empty()) {
            return 0;
        }

        for(int i = 1; i < static_cast<int>(nums.size()); i++) {
            if(nums[i] > nums[i-1]) {
                currentLen++;
                maxlen = max(maxlen, currentLen);
            }
            else {
                currentLen = 1;
            }
        }

        return maxlen;
    }
};
```

## Example

**Input:**
```text
nums = [1,3,5,4,7]
```

**Dry Run:**

| i | nums[i-1] | nums[i] | Condition | currentLen | maxlen |
|---|---:|---:|---|---:|---:|
| 1 | 1 | 3 | Increasing | 2 | 2 |
| 2 | 3 | 5 | Increasing | 3 | 3 |
| 3 | 5 | 4 | Not increasing | 1 | 3 |
| 4 | 4 | 7 | Increasing | 2 | 3 |

**Output:**
```text
3
```

## Complexity Analysis

Let `n` be the size of the input array.

- **Time Complexity: O(n)** – We traverse the array once, performing constant-time comparisons and updates.
- **Space Complexity: O(1)** – We use only two additional variables, `currentLen` and `maxlen`.

## Key Concepts Learned

- Continuous subarrays.
- Comparing adjacent array elements.
- Maintaining a running count.
- Resetting a counter when a condition breaks.
- Tracking maximum values using `max()`.
- Handling empty arrays using `empty()`.
- Using `static_cast<int>()` for explicit type conversion.