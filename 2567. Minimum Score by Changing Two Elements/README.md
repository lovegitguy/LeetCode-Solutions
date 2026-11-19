# LeetCode 2567: Minimum Score by Changing Two Elements

## Problem

You are given a 0-indexed integer array `nums`.

The **score** of the array is defined as the difference between the maximum and minimum elements.

You can change the value of at most two elements in the array to any other integer.

Return the minimum possible score after changing at most two elements.

**Example:**

- Input: `nums = [1, 4, 7, 8, 5]`
- Output: `3`

---

## Approach

We use **Sorting + Greedy Approach** to minimize the difference between the largest and smallest elements.

### 1. Sort the Array

First, sort the array in ascending order using `ranges::sort(nums)`.

After sorting:
- The smallest element is at index `0`.
- The largest element is at index `n-1`.

### 2. Understand the Three Possible Cases

Since we can change at most two elements, we need to consider three possible ways to eliminate the extreme values.

**Case 1: Change the Two Smallest Elements**

After changing the two smallest elements, the new minimum can be `nums[2]`, while the maximum remains `nums[n-1]`.

Difference:

`nums[n-1] - nums[2]`

**Case 2: Change the Two Largest Elements**

After changing the two largest elements, the maximum can be `nums[n-3]`, while the minimum remains `nums[0]`.

Difference:

`nums[n-3] - nums[0]`

**Case 3: Change the Smallest and Largest Elements**

After changing the smallest and largest elements, the remaining minimum is `nums[1]` and the remaining maximum is `nums[n-2]`.

Difference:

`nums[n-2] - nums[1]`

Finally, calculate all three differences and return the minimum.

### Key Concept: Sorting + Greedy

Sorting allows us to identify the extreme elements easily.

The greedy idea is to modify the elements responsible for increasing the difference between the maximum and minimum values.

Instead of checking every possible pair, we only need to consider three possible distributions of the two changes across the sorted array.

---

## C++ Solution

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        ranges::sort(nums);

        const int n = nums.size();

        const int highOfChangingTwoMins = nums.back() - nums[2];
        const int highOfChangingTwoMaxs = nums[n - 3] - nums[0];
        const int highOfChangingMinAndMax = nums[n - 2] - nums[1];

        return min({
            highOfChangingTwoMins,
            highOfChangingTwoMaxs,
            highOfChangingMinAndMax
        });
    }
};
```

---

## Example

**Input:**

```cpp
nums = [1, 4, 7, 8, 5]
```

After sorting:

```cpp
nums = [1, 4, 5, 7, 8]
```

Array size:

```cpp
n = 5
```

Calculate all three possibilities:

| Case | Calculation | Difference |
|---|---|---|
| Change two smallest | `8 - 5` | 3 |
| Change two largest | `5 - 1` | 4 |
| Change smallest and largest | `7 - 4` | 3 |

Minimum difference:

```cpp
min(3, 4, 3) = 3
```

**Output:**

```cpp
3
```

---

## Complexity Analysis

**Time Complexity: O(n log n)**

- Sorting the array takes O(n log n).
- Calculating the three possible differences takes O(1).
- Overall complexity is O(n log n).

**Space Complexity: O(1)** auxiliary space

- Only a constant number of integer variables are used.
- Sorting may require implementation-dependent auxiliary space.

---

## Key Takeaways

- Learned to apply sorting to optimization problems.
- Practiced the Greedy approach.
- Understood how changing extreme elements affects the overall range.
- Learned to reduce a problem involving multiple possible choices into three cases.
- Practiced `ranges::sort()`, `nums.back()`, and `min()` with an initializer list.