# Find Mismatched Segments

## Problem Overview
Given two strings `s1` and `s2` of equal length, identify all continuous segments where the characters at corresponding positions differ.

For each continuous mismatched segment, return:
- The substring from `s1`.
- The corresponding substring from `s2`.

Store each pair of substrings in a 2D vector.

## Approach: Single Pass Traversal

We traverse both strings simultaneously using a single loop.

We maintain a variable `start` to track the starting index of a mismatched segment.

### Algorithm

1. Initialize an empty 2D vector `answer`.
2. Initialize `start = -1`, indicating that no mismatched segment is currently active.
3. Traverse both strings using index `i`.
4. If `s1[i] != s2[i]`:
   - If `start == -1`, mark the current index as the beginning of a mismatched segment.
5. If `s1[i] == s2[i]`:
   - If a mismatched segment is active:
     - Calculate its length using `i - start`.
     - Extract corresponding substrings from both strings using `substr()`.
     - Store them as a pair in `answer`.
     - Reset `start = -1`.
6. After the loop, check whether a mismatched segment is still active.
   - If yes, extract and store the remaining substrings.
7. Return `answer`.

## C++ Concepts Used

- **2D Vector:** `vector<vector<string>>` stores pairs of mismatched substrings.
- **String Comparison:** `s1[i] != s2[i]` checks whether corresponding characters differ.
- **Substring:** `substr(start, len)` extracts a portion of a string.
- **State Tracking:** `start` tracks whether a mismatched segment is active.
- **Single-Pass Traversal:** Both strings are processed simultaneously.

## Example

**Input:**
```cpp
s1 = "abcdefghi";
s2 = "abXdeYghi";
```

**Output:**
```cpp
{
    {"c", "X"},
    {"f", "Y"}
}
```

## Complexity Analysis

Let `n` be the length of the strings and `k` be the total number of characters across all extracted substrings in both strings.

- **Time Complexity:** O(n) — Traversing the strings takes O(n), and extracting all substrings takes O(n) in total.
- **Auxiliary Space Complexity:** O(1) — Only a few variables are used, excluding the returned answer.
- **Output Space Complexity:** O(k) — Stores the extracted substrings.

## Key Learning

This problem demonstrates how to identify continuous groups of elements satisfying a condition using a single traversal.

The important idea is **tracking the beginning of a segment and closing it when the condition stops being true**.

This pattern is useful in:
- Identifying consecutive mismatches.
- Finding continuous ranges.
- Grouping adjacent elements based on a condition.
- Processing sequences using state tracking.