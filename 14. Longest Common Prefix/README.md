# 14. Longest Common Prefix

## Approach: Vertical Scanning

### Intuition
The goal is to find the longest prefix that is common to every string in the given array.

We use the first string as our reference and compare its characters with the corresponding characters of all other strings.

Before comparing characters, we calculate the minimum string length because a common prefix cannot be longer than the shortest string.

### Algorithm

1. Initialize an empty string `commonPrefix` to store the result.
2. Initialize `boundary` with the length of the first string.
3. Traverse the remaining strings and update `boundary` to the minimum string length.
4. Iterate through the first string, but only up to `boundary`.
5. For every character at index `i`:
   - Compare it with the character at the same index in every other string.
   - If any character does not match, return `commonPrefix`.
   - Otherwise, append the matching character to `commonPrefix`.
6. Return `commonPrefix` after all comparisons are complete.

### C++ Concepts Used
- `vector<string>` – Stores multiple strings.
- `string.size()` – Returns the length of a string.
- `min()` – Finds the minimum string length.
- Nested `for` loops – Compare characters across multiple strings.
- String indexing – Access characters using `strs[i][j]`.
- `return` – Exits immediately when a mismatch is found.

### Complexity Analysis

Let:
- `n` = Number of strings.
- `m` = Length of the shortest string.

**Time Complexity: O(n × m)**

- Finding the minimum string length takes O(n).
- Comparing characters across all strings takes O(n × m) in the worst case.

**Space Complexity: O(m)**

- The `commonPrefix` string stores at most `m` characters.

### Key Learning
This problem introduces **Vertical Scanning**.

Instead of comparing strings one by one, we compare characters column by column.

For example:

```text
flower
flow
flight

Index 0: f f f  ✓
Index 1: l l l  ✓
Index 2: o o i  ✗

Longest Common Prefix = "fl"
```

The moment a mismatch occurs, we know that no longer common prefix is possible.