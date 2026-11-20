# LeetCode 680: Valid Palindrome II

## Problem

Given a string `s`, return `true` if the string can become a palindrome after deleting at most one character.

A palindrome is a string that reads the same forward and backward.

**Example 1:**

```text
Input: s = "aba"
Output: true
Explanation: The string is already a palindrome.
```

**Example 2:**

```text
Input: s = "abca"
Output: true
Explanation: Delete 'b' or 'c' to make "aca" or "aba".
```

**Example 3:**

```text
Input: s = "abc"
Output: false
```

## Approach

We use **Two Pointers + Recursion**.

The two-pointer technique allows us to compare characters from both ends of the string while moving toward the center.

### Step 1: Initialize Two Pointers

- `start` points to the first character.
- `end` points to the last character.

### Step 2: Compare Characters

While `start < end`:

- If both characters match, move both pointers inward.
- If they don't match, we are allowed to delete at most one character.

### Step 3: Handle a Mismatch Using Recursion

When a mismatch occurs, we have two possible choices:

**Choice 1: Ignore the left character**

```cpp
ispalindrome(s, start + 1, end)
```

Move the left pointer forward, effectively skipping the left character.

**Choice 2: Ignore the right character**

```cpp
ispalindrome(s, start, end - 1)
```

Move the right pointer backward, effectively skipping the right character.

If either possibility produces a palindrome, return `true`.

We combine both possibilities using the logical OR operator:

```cpp
return ispalindrome(s, start + 1, end) ||
       ispalindrome(s, start, end - 1);
```

### Step 4: Base Case

If the pointers cross or meet without finding another mismatch, the remaining substring is a palindrome.

Therefore, return `true`.

## C++ Solution

```cpp
class Solution {
public:
    bool ispalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return ispalindrome(s, start + 1, end) ||
                       ispalindrome(s, start, end - 1);
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        return ispalindrome(s, start, end);
    }
};
```

## Example

**Input:**

```text
s = "abca"
```

**Execution:**

| Step | Left character | Right character | Action |
|---|---|---|---|
| 1 | a | a | Match; move inward |
| 2 | b | c | Mismatch; try skipping either character |
| 3 | b | b | Match after skipping `c` |
| 4 | Pointers meet | | Palindrome found |

Deleting either `b` or `c` produces a palindrome.

**Output:**

```text
true
```

## Complexity Analysis

Let `n` be the length of the string.

**Time Complexity:**

`O(n)`

In the worst case, we perform two linear palindrome checks after encountering a mismatch. Since there are at most two candidate checks, the total time remains linear.

**Space Complexity:**

`O(n)` worst case due to recursive call-stack usage.

## Key Concepts Learned

- Two Pointers.
- Palindrome checking.
- Recursion.
- Handling mismatches with multiple choices.
- Logical OR (`||`) for exploring alternative possibilities.
- Passing strings by constant reference (`const string &s`) to avoid unnecessary string copies.