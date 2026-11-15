# 844. Backspace String Compare

**Difficulty:** Easy  
**Topic:** String, Stack

## Problem

Given two strings `s` and `t`, determine whether they are equal when both are typed into an empty text editor.

The character `'#'` represents a backspace, meaning it removes the previous character if one exists.

Return `true` if both resulting strings are equal; otherwise, return `false`.

## Approach: Using Strings as Stacks

### Intuition

We can simulate the backspace operation using two additional strings.

A string naturally supports stack-like operations:
- `+=` adds a character to the end.
- `pop_back()` removes the last character.
- `empty()` checks whether the string contains any characters.

Since a backspace removes the most recently entered character, this follows the **LIFO (Last In, First Out)** principle.

### Algorithm

1. Create two empty strings `u` and `v`.
2. Traverse the first string `s`:
   - If the current character is `'#'`, remove the last character from `u` if it is not empty.
   - Otherwise, append the character to `u`.
3. Repeat the same process for string `t`, storing the result in `v`.
4. Compare `u` and `v`.
5. Return `true` if they are equal; otherwise, return `false`.

## C++ Solution

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string u = "";
        string v = "";

        for(char c : s) {
            if(c == '#') {
                if(!u.empty()) {
                    u.pop_back();
                }
            }
            else {
                u += c;
            }
        }

        for(char s : t) {
            if(s == '#') {
                if(!v.empty()) {
                    v.pop_back();
                }
            }
            else {
                v += s;
            }
        }

        if(u == v) {
            return true;
        }

        return false;
    }
};
```

## Complexity Analysis

Let `n` be the length of string `s` and `m` be the length of string `t`.

- **Time Complexity:** O(n + m) — Each string is traversed once.
- **Auxiliary Space Complexity:** O(n + m) — Two additional strings are used to store the processed results.

## Key Learnings

- Using strings as stacks.
- Understanding the LIFO principle.
- Using `pop_back()` to remove the most recently added character.
- Using `empty()` to prevent invalid removal.
- Simulating backspace operations.
- Comparing two processed strings.

## Takeaway

A string can be used as a stack when we only need insertion and deletion from the end. This makes it useful for problems involving backspaces, undo operations, and removing recently added elements.