# 1394. Find Lucky Integer in an Array

## Problem

Given an array of integers `arr`, a lucky integer is an integer whose frequency in the array is equal to its value.

Return the largest lucky integer. If no lucky integer exists, return `-1`.

## Approach: Hash Map (Frequency Counting)

We use an `unordered_map` to count how many times each integer appears.

### Logic

1. Create an `unordered_map<int, int>` to store the frequency of each element.
2. Traverse the array and increment the frequency using `answer[a]++`.
3. Initialize a variable `lucky = -1`.
4. Traverse the frequency map.
5. Check whether the key (`first`) is equal to its frequency (`second`).
6. If the condition is satisfied, update `lucky` with the maximum of its current value and the key.
7. Return `lucky`.

### C++ Solution

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> answer;

        for (int a : arr) {
            answer[a]++;
        }

        int lucky = -1;

        for (pair<int, int> a : answer) {
            if (a.first == a.second) {
                lucky = max(lucky, a.first);
            }
        }

        return lucky;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n) average — One traversal to count frequencies and another traversal over the distinct elements.
- **Space Complexity:** O(n) — The hash map stores the frequency of distinct elements.

## Key Learnings

- Frequency counting using `unordered_map`.
- Understanding key-value pairs using `.first` and `.second`.
- Checking conditions using map entries.
- Using `max()` to track the largest qualifying element.
- Why we should not immediately return the first matching element when the problem asks for the largest one.