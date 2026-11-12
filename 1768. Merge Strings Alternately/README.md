# 1768. Merge Strings Alternately

## Problem
Given two strings `word1` and `word2`, merge them by adding characters alternately, starting with `word1`.

If one string is longer than the other, append the remaining characters to the end of the merged string.

**Example:**

Input:
```cpp
word1 = "abc"
word2 = "pqr"
```

Output:
```cpp
"apbqcr"
```

Another example:

Input:
```cpp
word1 = "ab"
word2 = "pqrs"
```

Output:
```cpp
"apbqrs"
```

## Approach: Single Loop + Two Strings

### Logic

1. Create an empty string `ans` to store the merged result.
2. Initialize an index `i = 0`.
3. Use a `while` loop that continues as long as at least one string has characters remaining:

   ```cpp
   while(i < word1.size() || i < word2.size())
   ```

4. Check whether `i` is within the bounds of `word1`.
   - If yes, append `word1[i]` to `ans`.

5. Check whether `i` is within the bounds of `word2`.
   - If yes, append `word2[i]` to `ans`.

6. Increment `i` to move to the next position in both strings.
7. Return `ans`.

## Important Observation

We use the logical OR operator (`||`) in the loop condition because the loop must continue until **both strings are completely traversed**.

We use separate `if` conditions instead of `if-else` because we may need to append a character from both strings during the same iteration.

The individual boundary checks prevent accessing characters outside either string.

## C++ Concepts Used

- `string` – Storing the merged result.
- `while` loop – Traversing both strings.
- String indexing – Accessing characters using `word1[i]` and `word2[i]`.
- `+=` operator – Appending characters to a string.
- Logical OR (`||`) – Continuing while either string has characters remaining.
- Conditional statements – Handling strings of different lengths.

## Complexity Analysis

Let `n` be the length of `word1` and `m` be the length of `word2`.

**Time Complexity: O(n + m)**

Every character from both strings is visited and appended exactly once.

**Auxiliary Space Complexity: O(1)**

Only a constant number of extra variables are used, excluding the output string.

**Output Space Complexity: O(n + m)**

The resulting string stores all characters from both input strings.

## Key Learning

Two strings of different lengths can be traversed together using a single index.

The key is to:
- Continue while at least one string has characters remaining.
- Independently check the boundaries of both strings.
- Append characters only when their indices are valid.

**Pattern:** String Traversal + Two Pointers / Index-Based Merging.