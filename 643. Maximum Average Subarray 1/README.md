# 643. Maximum Average Subarray I

**Difficulty:** Easy  
**Topics:** Array, Sliding Window  
**Language:** C++

## Problem

Given an integer array `nums` consisting of `n` elements and an integer `k`, find the contiguous subarray of length `k` that has the maximum average value.

Return the maximum average.

## Approach: Fixed-Size Sliding Window

Instead of calculating the sum of every possible subarray from scratch, we use the Sliding Window technique.

Since the subarray must contain exactly `k` elements, we maintain a window of fixed size.

### Step 1: Calculate the First Window

Calculate the sum of the first `k` elements.

```cpp
double current_sum = 0;

for(int i = 0; i < k; i++) {
    current_sum += nums[i];
}
```

This gives us the sum of the initial window.

### Step 2: Initialize Maximum Sum

```cpp
double max_sum = current_sum;
```

Initially, the first window is our best window.

### Step 3: Slide the Window

Move the window one position to the right.

```cpp
current_sum = current_sum + nums[i] - nums[i-k];
```

For every movement:

1. Add the newly included element `nums[i]`.
2. Remove the element leaving the window `nums[i-k]`.
3. Update `max_sum` if the new window has a larger sum.

```cpp
max_sum = max(max_sum, current_sum);
```

### Step 4: Calculate Maximum Average

Since every window contains exactly `k` elements:

```cpp
return max_sum / k;
```

## C++ Solution

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;

        for(int i = 0; i < k; i++) {
            current_sum += nums[i];
        }

        double max_sum = current_sum;

        for(int i = k; i < nums.size(); ++i) {
            current_sum = current_sum + nums[i] - nums[i-k];

            max_sum = max(max_sum, current_sum);
        }

        return max_sum / k;
    }
};
```

## Example

**Input:**

```cpp
nums = {1, 12, -5, -6, 50, 3};
k = 4;
```

### Dry Run

First window:

```text
1 + 12 + (-5) + (-6) = 2
```

Initial maximum sum = 2.

Now slide the window:

| Window           | Calculation    | Sum |
| ---------------- | -------------- | --: |
| [1, 12, -5, -6]  | Initial window |   2 |
| [12, -5, -6, 50] | 2 + 50 - 1     |  51 |
| [-5, -6, 50, 3]  | 51 + 3 - 12    |  39 |

Maximum sum = 51.

Maximum average:

```cpp
51 / 4 = 12.75
```

**Output:** `12.75000`

## Complexity Analysis

Let `n` be the number of elements in the array.

- **Time Complexity:** O(n) — The first window requires O(k), and the remaining elements are processed once. Overall O(n).
- **Auxiliary Space Complexity:** O(1) — Only a few variables are maintained.

## Key Learnings

1. **Sliding Window:** Efficiently process contiguous subarrays.
2. **Fixed-Size Window:** Maintain a window containing exactly `k` elements.
3. **Incremental Updates:** Add the incoming element and subtract the outgoing element.
4. **Avoid Recalculation:** Instead of summing every window from scratch, reuse the previous window's sum.
5. **Optimization:** Reduce the brute-force O(n × k) approach to O(n).

## Important Formula

```cpp
new_window_sum = previous_window_sum
                 + incoming_element
                 - outgoing_element;
```

This formula is the foundation of fixed-size sliding window problems.
