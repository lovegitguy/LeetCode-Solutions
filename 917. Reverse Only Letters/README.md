# 917. Reverse Only Letters

**Difficulty:** Easy  
**Topics:** String, Two Pointers

## Problem

Given a string `s`, reverse only the letters in the string while keeping all non-letter characters at their original positions.

Return the resulting string.

### Example

```text
Input:  s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

## Approach: Two Pointers

### Intuition

We use two pointers:
- `start` begins at the first character.
- `end` begins at the last character.

The objective is to swap letters from opposite ends while leaving non-letter characters untouched.

### Algorithm

1. Initialize `start = 0` and `end = s.size() - 1`.
2. Continue while `start < end`.
3. If the character at `end` is not a letter:
   - Decrement `end`.
   - Use `continue` to skip the remaining operations in the current iteration.
4. If the character at `start` is not a letter:
   - Increment `start`.
   - Use `continue` to skip the remaining operations.
5. If both positions contain letters:
   - Swap `s[start]` and `s[end]`.
   - Increment `start` and decrement `end`.
6. Return the modified string.

## C++ Solution

```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {

        int start = 0;
        int end = s.size() - 1;

        while(start < end) {

            if(!isalpha(s[end])) {
                end--;
                continue;
            }

            if(!isalpha(s[start])) {
                start++;
                continue;
            }

            swap(s[start], s[end]);
            start++;
            end--;
        }

        return s;
    }
};
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** O(n) — Both pointers traverse the string, moving toward each other.
- **Auxiliary Space Complexity:** O(1) — The string is modified in place, and only two pointer variables are used.

## Key Learnings

- Understanding the two-pointer technique.
- Using two pointers to traverse a string from opposite directions.
- Using `isalpha()` to identify alphabetic characters.
- Using `swap()` to exchange characters.
- Understanding `continue` and how it skips the remaining statements in the current loop iteration.
- Modifying strings in place.

## Takeaway

The two-pointer technique is useful when elements need to be rearranged from opposite ends of an array or string.

By independently skipping characters that don't satisfy a condition, we can perform selective reversal without using additional storage.