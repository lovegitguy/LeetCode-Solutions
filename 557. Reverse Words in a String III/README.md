# 557. Reverse Words in a String III

## Problem
Given a string `s`, reverse the characters of each word in the string while preserving the original order of words and spaces.

**Example:**

Input:
```cpp
s = "Let's take LeetCode contest"
```

Output:
```cpp
"s'teL ekat edoCteeL tsetnoc"
```

## Approach: Two Pointers + Word Boundary Detection

Instead of splitting the string into separate words, reverse each word directly inside the original string.

### Logic

1. Calculate the string length using `s.size()`.
2. Initialize `start = 0` to mark the beginning of the current word.
3. Traverse the string using a `for` loop.
4. Whenever we encounter a space or reach the end of the string:
   - Set `left = start`.
   - Set `right = i - 1`.
5. Use a `while` loop while `left < right`:
   - Swap `s[left]` and `s[right]`.
   - Increment `left`.
   - Decrement `right`.
6. Update `start = i + 1` to mark the beginning of the next word.
7. Return the modified string.

### Important Observation

We use:

```cpp
if(i == n || s[i] == ' ')
```

The `i == n` condition handles the last word because there may not be a space after it.

We use `i <= n` in the loop so that the final word also gets reversed.

## C++ Concepts Used

- `string` – Working with strings.
- `size()` – Getting the string length.
- Two pointers – Using `left` and `right` to reverse characters.
- `swap()` – Exchanging characters.
- `while` loop – Reversing each word.
- In-place modification – Modifying the original string without creating another string.

## Complexity Analysis

**Time Complexity: O(n)**

Every character is visited during traversal, and each character participates in at most one swap.

**Space Complexity: O(1)**

The reversal is performed directly in the original string using a constant number of variables.

## Key Learning

A string doesn't always need to be split into words before processing.

We can detect word boundaries using spaces and reverse each word independently using two pointers.

**Pattern:** String Traversal + Two Pointers + In-place Reversal.