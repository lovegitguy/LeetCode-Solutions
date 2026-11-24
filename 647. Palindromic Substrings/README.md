# LeetCode 647: Palindromic Substrings

## Problem

Given a string `s`, return the total number of palindromic substrings in it.

A palindrome is a string that reads the same forward and backward.

Every occurrence must be counted separately, even if multiple substrings contain the same characters.

## Approach

We use two nested loops to generate every possible non-empty substring.

### Step 1: Generate Substrings

- The outer loop selects the starting index `i`.
- The inner loop selects the ending index `j`.
- We use `substr(i, j - i + 1)` to extract the substring.

### Step 2: Check Whether It Is a Palindrome

For every generated substring:

1. Create a copy called `reversed`.
2. Reverse it using `reverse()`.
3. Compare the original substring with the reversed copy.
4. If both are equal, increment `count`.

Finally, return the total count.

## Key Concepts

### 1. Substring Generation

```cpp
string current = s.substr(i, j - i + 1);
```

`substr()` accepts:

- Starting index.
- Length of the substring.

Therefore, the length is calculated as:

\[
j-i+1
\]

### 2. Reversing a String

```cpp
string reversed = current;
reverse(reversed.begin(), reversed.end());
```

We create a copy because `reverse()` modifies the original string directly.

### 3. Palindrome Checking

A string is a palindrome if:

```cpp
current == reversed
```

## C++ Solution

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string current = s.substr(i, j - i + 1);

                string reversed = current;
                reverse(reversed.begin(), reversed.end());

                if (current == reversed) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

## Example

**Input:**
```text
s = "aaa"
```

**Output:**
```text
6
```

**Explanation:**

All possible substrings are:

| Substring | Palindrome? |
|---|---|
| a | Yes |
| a | Yes |
| a | Yes |
| aa | Yes |
| aa | Yes |
| aaa | Yes |

Total palindromic substrings = 6.

Notice that repeated occurrences are counted separately.

## Complexity Analysis

Let `n` be the length of the string.

- **Time Complexity:** \(O(n^3)\).
  - There are \(O(n^2)\) possible substrings.
  - Creating, reversing, and comparing a substring can take \(O(n)\) time.
- **Auxiliary Space Complexity:** \(O(n)\) for the temporary substring and its reversed copy.

## Further Optimization

The brute-force approach checks every possible substring independently.

A more efficient technique is **Expand Around Center**, which checks palindromes by expanding outward from every possible center.

This reduces the time complexity to:

\[
O(n^2)
\]

with \(O(1)\) auxiliary space.
