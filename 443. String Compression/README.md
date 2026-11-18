# LeetCode 443: String Compression

## Problem

Given an array of characters `chars`, compress it using the following rules:

1. For each group of consecutive repeating characters, keep only one occurrence of the character.
2. If a character repeats more than once, append the number of repetitions immediately after the character.
3. If a character appears only once, do not append a count.

Modify the input array **in-place** and return the new length of the compressed array.

The algorithm must use constant extra space.

## Approach

We can solve this problem using **Two Pointers and Counting**.

We use two main pointers:

- `i`: Reads the original characters and identifies consecutive groups.
- `ans`: Keeps track of the position where compressed characters should be written.

### Steps

1. Initialize `ans = 0` to track the position for writing compressed characters.
2. Traverse the array using `i`.
3. Store the current character in `letter`.
4. Initialize `count = 0` to count consecutive occurrences.
5. Use a `while` loop to count all consecutive occurrences of `letter`.
   - Increment `count`.
   - Increment `i` to move forward.
6. Write the character at `chars[ans++]`.
7. If `count > 1`, convert the count into a string using `to_string(count)`.
8. Traverse the resulting count string and write each digit into the original array.
9. Continue until all characters have been processed.
10. Return `ans`, which represents the compressed array's length.

### Key Concept: In-Place Modification

Instead of creating another array to store the compressed result, we modify the original array itself.

The `ans` pointer always indicates where the next compressed character should be written.

Since we process groups from left to right, the write position never moves ahead of the read position. Therefore, we can safely overwrite the original array without losing unprocessed characters.

### Key Concept: Counting Consecutive Characters

The inner `while` loop counts how many times the current character appears consecutively.

For example:

```text
Input:  ["a", "a", "b", "b", "c", "c", "c"]

Groups:
"a" -> 2
"b" -> 2
"c" -> 3
```

The compressed result becomes:

```text
["a", "2", "b", "2", "c", "3"]
```

## C++ Solution

```cpp
class Solution {
 public:
  int compress(vector<char>& chars) {
    int ans = 0;

    for (int i = 0; i < chars.size();) {
      const char letter = chars[i];
      int count = 0;

      while (i < chars.size() && chars[i] == letter) {
        ++count;
        ++i;
      }

      chars[ans++] = letter;

      if (count > 1)
        for (const char c : to_string(count))
          chars[ans++] = c;
    }

    return ans;
  }
};
```

## Example

**Input:**

```text
chars = ["a","a","b","b","c","c","c"]
```

**Output:**

```text
6
```

**Explanation:**

We identify consecutive groups:

| Character | Count | Compressed Representation |
|---|---:|---|
| a | 2 | a2 |
| b | 2 | b2 |
| c | 3 | c3 |

The resulting array is:

```text
["a","2","b","2","c","3"]
```

The compressed array contains 6 characters, so we return `6`.

## Complexity Analysis

**Time Complexity: O(n)**

- The outer loop processes each group of consecutive characters.
- The inner `while` loop traverses every character exactly once across all groups.
- Converting counts to strings and writing their digits also takes linear total time.

Therefore, the overall time complexity is **O(n)**.

**Space Complexity: O(1)**

- We modify the original array directly.
- We use only a few additional variables.
- No separate result array is created.

The algorithm uses constant auxiliary space.

## Key Takeaway

This problem demonstrates an important application of the **Two Pointer Technique**:

- Read pointer (`i`): Identifies and counts consecutive characters.
- Write pointer (`ans`): Stores the compressed result in-place.

It also introduces useful C++ concepts:

- `to_string()` to convert an integer into a string.
- `const char` to store a character that should not be modified.
- Range-based `for` loops to iterate through the digits of a string.

The main lesson is that we can efficiently transform an array in-place using separate read and write positions.