# Count Suffix

## Problem Overview

Given two integer arrays, `nums` and `target`, determine the number of valid suffix operations based on the relationship between their elements.

The solution first checks whether both arrays contain the same elements with the same frequencies. If they do, it identifies the relevant index boundaries and calculates the number of valid positions.

## Approach

The solution uses three main techniques:

1. Frequency counting.
2. First mismatch detection.
3. Index tracking using consecutive comparisons.

### 1. Frequency Comparison

```cpp
vector<int> freq(100001, 0);

for(int i = 0; i < n; i++) {
    freq[nums[i]]++;
    freq[target[i]]--;
}
```

- Increment the frequency for every element in `nums`.
- Decrement the frequency for every element in `target`.
- If any frequency is non-zero, the arrays do not contain the same elements with the same frequencies.
- Return `0` in that case.

This checks whether both arrays have identical element frequencies.

### 2. First Mismatch Detection

```cpp
int firstMismatch = n;

for(int i = 0; i < n; i++) {
    if(nums[i] != target[i]) {
        firstMismatch = i;
        break;
    }
}
```

Find the first index where the corresponding elements differ.

If no mismatch exists, `firstMismatch` remains `n`.

### 3. Finding the Minimum Index

```cpp
int minIndex = 0;

for(int i = 0; i < n - 1; i++) {
    if(target[i] < target[i + 1]) {
        minIndex = i + 1;
    }
}
```

Traverse the `target` array and update `minIndex` whenever an element is smaller than its next element.

This tracks the position following the last adjacent increasing pair.

### 4. Calculating the Answer

```cpp
int maxIndex = min(firstMismatch, n - 1);

return max(0, maxIndex - minIndex + 1);
```

- `maxIndex` establishes the upper boundary.
- `minIndex` establishes the lower boundary.
- Calculate the number of positions in the inclusive range.
- `max(0, ...)` prevents a negative result.

## C++ Concepts Used

- `vector<int>` for frequency counting.
- Frequency arrays for comparing element distributions.
- `break` for stopping at the first mismatch.
- `min()` and `max()` for boundary calculations.
- `auto` and `make_pair()` for creating a pair.
- Single-pass array traversal.

## Complexity Analysis

Let `n` be the size of both arrays and `M = 100000`.

| Operation | Time Complexity |
|---|---|
| Frequency counting | O(n) |
| Frequency verification | O(M) |
| First mismatch detection | O(n) |
| Minimum index tracking | O(n) |
| Final calculation | O(1) |

**Overall Time Complexity:** O(n + M)

**Space Complexity:** O(M) due to the frequency array.

## Key Learning

This problem combines multiple array-processing techniques:

1. Frequency counting to verify whether two arrays contain identical elements.
2. First mismatch detection to establish a boundary.
3. Index tracking to identify a valid range.
4. Mathematical range calculation using inclusive indices.