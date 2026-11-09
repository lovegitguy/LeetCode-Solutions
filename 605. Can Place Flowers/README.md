# 605. Can Place Flowers

**Difficulty:** Easy  
**Topics:** Array, Greedy  
**Language:** C++

## Problem

Given an integer array `flowerbed` containing `0`s and `1`s, where `0` represents an empty position and `1` represents a planted flower, determine whether `n` new flowers can be planted without violating the no-adjacent-flowers rule.

Return `true` if all `n` flowers can be planted; otherwise, return `false`.

## Approach: Greedy Algorithm

Traverse the flowerbed from left to right and check whether each position is suitable for planting.

A flower can be planted at index `i` if:

1. The current position is empty.
2. The left position is empty or does not exist.
3. The right position is empty or does not exist.

If all three conditions are satisfied, plant a flower at the current position and decrease `n` by one.

Updating the current position immediately ensures that subsequent iterations recognize the newly planted flower.

## C++ Solution

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for(int i = 0; i < size; i++) {
            int left = (i == 0) ? 0 : flowerbed[i-1];

            int right = (i == size-1) ? 0 : flowerbed[i+1];

            if(left + flowerbed[i] + right == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }

        return n <= 0;
    }
};
```

## Example

**Input:**
```cpp
flowerbed = {1, 0, 0, 0, 1};
n = 1;
```

**Traversal:**

- Index 0: Already occupied.
- Index 1: Cannot plant because the left position contains a flower.
- Index 2: Both neighbors are empty. Plant a flower.
- Index 3: Cannot plant because index 2 is now occupied.
- Index 4: Already occupied.

**Final flowerbed:**
```cpp
{1, 0, 1, 0, 1}
```

**Output:** `true`

## Complexity Analysis

- **Time Complexity:** O(n) where n here represents the length of the flowerbed. Each position is visited once.
- **Auxiliary Space Complexity:** O(1). Only a few additional integer variables are used.

## Key Learnings

1. **Greedy Algorithm:** Make a valid planting decision as soon as possible while traversing from left to right.
2. **Boundary Conditions:** Handle the first and last positions without accessing invalid indices.
3. **Ternary Operator:** Use conditional expressions to simplify boundary checks.
4. **In-place Modification:** Update the original vector instead of creating another array.
5. **Neighbor Checking:** Use adjacent elements to determine whether an operation is valid.