# 709. To Lower Case

## Problem
Given a string `s`, convert all uppercase English letters into lowercase letters and return the resulting string. All other characters should remain unchanged.

## Approach: ASCII Value Checking + String Traversal

1. Create an empty string `output` to store the converted string.
2. Traverse the input string character by character using a `for` loop.
3. Check whether the ASCII value of the current character lies between `65` and `90` (uppercase English letters).
   - If yes, convert the character into lowercase using `tolower()` and append it to `output`.
   - Otherwise, append the original character without modification.
4. Return the final `output` string.

## C++ Concepts Used

- **String Traversal:** Accessing characters using their indices.
- **ASCII Values:**
  - Uppercase `A` = 65
  - Uppercase `Z` = 90
  - Lowercase `a` = 97
  - Lowercase `z` = 122
- **`tolower()`:** Converts an uppercase character into its lowercase equivalent.
- **`+=` Operator:** Appends individual characters to a string.
- **Conditional Statements:** Determines whether a character needs conversion.

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** O(n) — We traverse the string exactly once.
- **Space Complexity:** O(n) — We create a separate output string to store the result.

## Key Learning

ASCII values can help identify uppercase English letters through a simple range check.

The `tolower()` function performs the actual conversion, while the conditional statement ensures that characters already in lowercase or non-alphabetic characters remain unchanged.

**Important:** We can also simplify the condition by using `s[i] >= 'A' && s[i] <= 'Z'` instead of checking ASCII values explicitly.

