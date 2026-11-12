# 520. Detect Capital

## Problem
Given a string `word`, determine whether the capitalization is used correctly.

Capitalization is considered correct if:
1. All letters are uppercase. Example: `"USA"`
2. All letters are lowercase. Example: `"leetcode"`
3. Only the first letter is uppercase. Example: `"Google"`

Return `true` if the capitalization is correct; otherwise, return `false`.

## Approach: Count Uppercase Characters

Instead of checking every possible capitalization pattern separately, count the total number of uppercase characters in the string.

### Logic

1. Initialize `uppercount = 0`.
2. Traverse the string using a `for` loop.
3. If `isupper(word[i])` returns true, increment `uppercount`.
4. Check the following conditions:

   - **All uppercase:** If `uppercount == word.size()`, return `true`.
   - **All lowercase:** If `uppercount == 0`, return `true`.
   - **First letter uppercase:** If `uppercount == 1` and `word[0]` is uppercase, return `true`.
   - Otherwise, return `false`.

## C++ Concepts Used

- `for` loop – Traversing the string.
- `isupper()` – Checking whether a character is uppercase.
- `word.size()` – Getting the length of the string.
- Counter variable – Counting uppercase characters.
- Conditional statements – Validating capitalization patterns.

## Complexity Analysis

- **Time Complexity:** O(n) – We traverse the string once.
- **Space Complexity:** O(1) – We use only one additional variable (`uppercount`).

## Key Learning

The important idea is that we don't need to compare the string against predefined patterns.

By counting uppercase characters and checking their position when necessary, we can validate all three capitalization rules efficiently.

**Pattern:** Character Counting + Conditional Logic.