# 1748. Sum of Unique Elements

## Problem

Given an integer array `nums`, return the sum of all elements that appear exactly once in the array.

## Approach: Hash Map (Frequency Counting)

We can use an `unordered_map` to store the frequency of every element.

### Logic

1. Create an `unordered_map<int, int>` called `frequency`.
2. Traverse the array and increment the frequency of each element using `frequency[n]++`.
3. Traverse the frequency map.
4. Check whether the frequency of each element is exactly `1`.
5. If it is, add that element to `sum`.
6. Return the final sum.

### C++ Solution

```cpp
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> frequency;
        int sum = 0;

        for (int n : nums) {
            frequency[n]++;
        }

        for (pair<int, int> f : frequency) {
            if (f.second == 1) {
                sum += f.first;
            }
        }

        return sum;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n) average — One traversal to count frequencies and another traversal over the distinct elements.
- **Space Complexity:** O(n) — The hash map stores the frequencies of distinct elements.

## Key Learnings

- Using `unordered_map` for frequency counting.
- Understanding key-value pairs.
- Accessing `pair.first` for the key and `pair.second` for the value.
- Using `frequency[n]++` to increment frequencies.
- Filtering elements based on their occurrence count.