# 303. Range Sum Query – Immutable

**Difficulty:** Easy  
**Topics:** Array, Prefix Sum  
**Language:** C++

## Problem

Given an integer array `nums`, handle multiple queries of the following type:

Calculate the sum of elements between indices `left` and `right`, inclusive.

Implement the `NumArray` class with:
- `NumArray(vector<int>& nums)`: Initializes the object with the given array.
- `sumRange(int left, int right)`: Returns the sum of elements from index `left` to index `right`, inclusive.

## Approach: Prefix Sum

Instead of calculating the sum from scratch for every query, we precompute cumulative sums using a prefix sum array.

We create a prefix array of size `nums.size() + 1`.

The extra position at the beginning stores zero.

### Prefix Sum Formula

```cpp
prefix[i+1] = prefix[i] + nums[i];
```

To calculate the sum between indices `left` and `right`:

```cpp
prefix[right+1] - prefix[left]
```

Why?

`prefix[right+1]` contains the sum from index `0` through `right`.

Subtracting `prefix[left]` removes all elements before `left`.

The remaining value is exactly the required range sum.

## C++ Solution

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums)
        : prefix(nums.size() + 1) {
        partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

private:
    vector<int> prefix;
};
```

## Example

**Input:**

```cpp
nums = {-2, 0, 3, -5, 2, -1};
```

After calculating prefix sums:

| Index | nums[i] | prefix[i+1] |
|---|---:|---:|
| 0 | -2 | -2 |
| 1 | 0 | -2 |
| 2 | 3 | 1 |
| 3 | -5 | -4 |
| 4 | 2 | -2 |
| 5 | -1 | -3 |

Prefix array:

```cpp
prefix = {0, -2, -2, 1, -4, -2, -3};
```

**Query:**

```cpp
sumRange(2, 5);
```

Calculation:

```cpp
prefix[5+1] - prefix[2]
= prefix[6] - prefix[2]
= -3 - (-2)
= -1
```

**Output:** `-1`

## C++ STL Concept: partial_sum()

`partial_sum()` is available in the `<numeric>` header.

It calculates cumulative sums of elements in a range.

Syntax:

```cpp
partial_sum(first, last, result);
```

In our solution:

```cpp
partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
```

- `nums.begin()` — Starting position of input.
- `nums.end()` — Ending position of input.
- `prefix.begin() + 1` — Starting position where cumulative sums are stored.

We start at index 1 because `prefix[0]` must remain zero.

## Complexity Analysis

Let `n` be the size of the input array.

| Operation | Complexity |
|---|---|
| Constructor / preprocessing | O(n) |
| Each sumRange query | O(1) |
| Auxiliary space | O(n) |

## Key Learnings

1. **Prefix Sum:** Store cumulative sums to answer range queries efficiently.
2. **Partial Sum:** Use C++ STL `partial_sum()` to calculate cumulative sums.
3. **Zero-based indexing:** An extra zero at the beginning simplifies range calculations.
4. **Range Sum Formula:** `prefix[right + 1] - prefix[left]`.
5. **Preprocessing:** Spend O(n) time once to make subsequent queries O(1).

The prefix sum technique is especially useful when multiple range-sum queries are performed on an array that does not change.