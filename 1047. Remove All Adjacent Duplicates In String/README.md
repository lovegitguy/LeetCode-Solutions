# LeetCode 1047: Remove All Adjacent Duplicates In String

## Problem

Given a string `s` consisting of lowercase English letters, repeatedly remove adjacent pairs of identical characters until no adjacent duplicates remain.

Return the final string after all possible removals.

**Example:**

```text
Input:  s = "abbaca"
Output: "ca"
```

**Explanation:**

- `"abbaca"` → Remove `"bb"` → `"aaca"`
- `"aaca"` → Remove `"aa"` → `"ca"`

The final string is `"ca"`.

## Approach

We use a **String as a Stack** to efficiently remove adjacent duplicate characters.

The idea is to maintain a string `ans` that stores the characters that have not been removed.

1. Initialize an empty string `ans`.
2. Traverse the input string character by character.
3. For each character `c`:
   - Check whether `ans` is empty.
   - If it is not empty, compare the last character of `ans` with `c` using `ans.back() == c`.
   - If both characters are equal, remove the last character using `pop_back()`.
   - Otherwise, add the current character using `push_back(c)`.
4. Return `ans`.

### Key Concept: String as a Stack

A string can behave like a stack using three operations:

- `push_back(c)` – Adds a character to the end.
- `pop_back()` – Removes the last character.
- `back()` – Accesses the last character.

This works because whenever two adjacent characters are equal, the most recently added character and the current character cancel each other out.

### Key Concept: Cascading Duplicate Removal

Removing one pair can create another adjacent duplicate pair.

For example:

```text
abbaca
  bb     → Remove
aaca
aa       → Remove
ca
```

The stack approach handles these cascading removals automatically because after removing the last character, the next incoming character is compared with the new last character.

## C++ Solution

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for(char c : s) {
            if(!ans.empty() && ans.back() == c) {
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
```

## Example

**Input:**

```text
s = "abbaca"
```

**Processing:**

| Current Character | Operation | ans |
|---|---|---|
| a | Push | a |
| b | Push | ab |
| b | Remove b | a |
| a | Remove a | Empty |
| c | Push | c |
| a | Push | ca |

**Output:**

```text
"ca"
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity: O(n)**

  We traverse the input string exactly once. Each character is pushed or causes one pop operation. Stack operations take O(1) amortized time.

- **Space Complexity: O(n)**

  In the worst case, no adjacent duplicates exist, so the resulting string stores all `n` characters.

## Key Takeaways

- A string can be used as a stack without declaring `stack<char>`.
- `back()` accesses the most recently added character.
- `pop_back()` removes the most recently added character.
- Always check `!ans.empty()` before accessing `ans.back()`.
- The stack pattern naturally handles cascading adjacent duplicate removals.