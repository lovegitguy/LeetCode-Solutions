# 28. Find the Index of the First Occurrence in a String

**Difficulty:** Easy  
**Topics:** String, String Matching, Two Pointers  
**Language:** C++

## Problem Statement

Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`.

If `needle` does not exist in `haystack`, return `-1`.

**Problem Link:** https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

## Approach: Brute Force String Matching

Use nested traversal to check whether `needle` exists in `haystack`.

The outer loop selects every possible starting position in `haystack`.

For each starting position, the inner loop compares characters of `needle` with the corresponding characters of `haystack`.

If all characters match, return the starting position.

Instead of checking every position in `haystack`, restrict the outer loop to `h - n` so that there are enough remaining characters to match `needle`.

## Algorithm

1. Calculate the lengths of both strings:
   - `h = haystack.size()`
   - `n = needle.size()`
2. If `n > h`, return `-1`.
3. Traverse `haystack` using an outer loop from `j = 0` to `j <= h - n`.
4. Initialize `i = 0` for every starting position.
5. Compare characters using:

   `haystack[j + i] == needle[i]`

6. If the characters match, increment `i` and continue comparing.
7. If `i == n`, all characters of `needle` have matched, so return `j`.
8. If no complete match is found, return `-1`.

## C++ Solution

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n > h) return -1;

        for (int j = 0; j <= h - n; j++) {
            int i = 0;

            while (i < n && haystack[j + i] == needle[i]) {
                i++;
            }

            if (i == n) {
                return j;
            }
        }

        return -1;
    }
};
```

## Example

**Input:**

```text
haystack = "sadbutsad"
needle = "sad"
```

**Output:**

```text
0
```

**Explanation:**

- Start checking from index `0` in `haystack`.
- Compare `haystack[0]` with `needle[0]`: `s == s`.
- Compare `haystack[1]` with `needle[1]`: `a == a`.
- Compare `haystack[2]` with `needle[2]`: `d == d`.
- All three characters match.

Therefore, the first occurrence of `needle` starts at index `0`.

## Complexity Analysis

**Time Complexity: O((h - n + 1) × n)**

There are at most `h - n + 1` possible starting positions.

For each starting position, the algorithm may compare up to `n` characters.

In the worst case, the time complexity is O(h × n).

**Auxiliary Space Complexity: O(1)**

Only a constant number of variables are used. No additional data structures are created.

## Key Learning

String matching can be performed by checking whether a smaller string exists inside a larger string.

The important concept is understanding the relationship between the two indices:

- `j` represents the starting position in `haystack`.
- `i` represents the current position in `needle`.
- `j + i` represents the corresponding position in `haystack`.

Using `haystack[j + i]` allows us to compare the characters at the correct relative positions.

The condition `i == n` confirms that every character of `needle` has matched successfully.