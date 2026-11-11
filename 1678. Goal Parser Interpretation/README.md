# 1678. Goal Parser Interpretation

## Problem
You are given a string `command` containing the patterns `"G"`, `"()"`, and `"(al)"`.

Interpret the command according to these rules:

- `"G"` → `"G"`
- `"()"` → `"o"`
- `"(al)"` → `"al"`

Return the final interpreted string.

## Approach: String Traversal + Pattern Matching

1. Create an empty string `answer` to store the interpreted output.
2. Traverse the input string character by character using a `for` loop.
3. Check the current character and identify the pattern:
   - If `command[i] == 'G'`, append `"G"` to the answer.
   - If `command.substr(i, 2) == "()"`, append `"o"`.
   - If `command.substr(i, 4) == "(al)"`, append `"al"`.
4. Return the final `answer` string.

## C++ Concepts Used

- **String Traversal:** Accessing each character using its index.
- **`substr()`:** Extracting a portion of a string.
  - `command.substr(i, 2)` extracts 2 characters starting at index `i`.
  - `command.substr(i, 4)` extracts 4 characters starting at index `i`.
- **Pattern Matching:** Comparing extracted substrings with predefined patterns.
- **String Concatenation (`+=`):** Appending characters or strings to the result.

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** O(n) — We traverse the command string once. Each substring comparison examines at most 4 characters, which is constant work.
- **Space Complexity:** O(n) — The output string stores the interpreted result.

## Key Learning

The `substr(starting_index, length)` function is useful for identifying patterns inside a string.

**Important Observation:** The loop does not need to skip characters after finding a pattern because the next iterations begin at positions containing `)` or `a`, which do not match any of the three starting patterns.

This approach helps understand how to recognize multiple patterns while traversing a string.

