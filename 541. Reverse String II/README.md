# 541. Reverse String II

## Problem
Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the beginning of the string.

Rules:
1. Reverse the first `k` characters.
2. Leave the next `k` characters unchanged.
3. Repeat this process for every `2k` characters.
4. If fewer than `k` characters remain, reverse all of them.
5. If between `k` and `2k` characters remain, reverse the first `k` and leave the rest unchanged.

## Approach 1: Using STL `reverse()`

### Logic

1. Calculate the length of the string using `s.size()`.
2. Traverse the string with a `for` loop, incrementing `i` by `2*k`.
3. Calculate the ending iterator:

   ```cpp
   int right = min(i + k, n);
   ```

4. Use STL `reverse()` to reverse the range:

   ```cpp
   reverse(s.begin() + i, s.begin() + right);
   ```

5. Return the modified string.

### Important Concepts

- `reverse()` reverses a range of elements.
- `begin()` returns an iterator pointing to the first character.
- `min()` ensures that we don't go beyond the string's length.
- `i += 2*k` skips the next `k` characters that should remain unchanged.

## Approach 2: Using Two Pointers

### Logic

1. Traverse the string in increments of `2*k`.
2. Initialize:
   - `start = i`
   - `end = min(start + k - 1, (int)s.size() - 1)`
3. Use a `while` loop while `start < end`.
4. Swap the characters at `start` and `end`.
5. Move both pointers towards the center:
   - `start++`
   - `end--`
6. Return the modified string.

### Why do we use `k - 1`?

String indexing starts from zero.

For example, if `k = 3`, the first three characters have indices:

`0, 1, 2`

Therefore, the ending index is:

`start + k - 1`

## Complexity Analysis

Let `n` be the length of the string.

| Complexity | Approach 1 | Approach 2 |
|---|---|---|
| Time | O(n) | O(n) |
| Auxiliary Space | O(1) | O(1) |

Both approaches have the same asymptotic complexity.

## C++ Concepts Learned

- STL `reverse()`
- `string.begin()`
- Iterators and iterator arithmetic
- `min()` function
- Two-pointer technique
- In-place string modification
- Loop increment patterns (`i += 2*k`)
- Type casting using `(int)`

## Key Learning

The important observation is that we don't need to reverse every `2*k` characters.

We only reverse the first `k` characters and skip the next `k`.

**Pattern:** String Traversal + Two Pointers / STL Algorithms.

## Personal Notes

Two different implementations solve the same problem:

- **Approach 1:** Shorter and cleaner using STL.
- **Approach 2:** Builds a stronger understanding of how reversal works internally using two pointers.

Understanding both implementations helps connect STL functions with the underlying logic.