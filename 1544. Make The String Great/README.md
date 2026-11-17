# LeetCode 1544: Make The String Great

## Problem

Given a string `s` consisting of uppercase and lowercase English letters, repeatedly remove adjacent characters if they represent the same letter but have different cases.

A string is considered good if it contains no such adjacent bad pairs.

Return the resulting good string.

**Example:**

```text
Input:  s = "leEeetcode"
Output: "leetcode"
```

**Explanation:**

The adjacent characters `E` and `e` represent the same letter but have different cases, so they are removed. This process continues until no bad adjacent pairs remain.

## Approach

We use a **String as a Stack** to process the characters efficiently.

The idea is to maintain a string `ans` that stores the characters that have not been removed.

1. Initialize an empty string `ans`.
2. Traverse the input string character by character.
3. For each character `c`:
   - Check whether `ans` is empty.
   - If it is not empty, compare the last character of `ans` with `c` using `isBadPair()`.
   - If they form a bad pair, remove the last character using `pop_back()`.
   - Otherwise, add the current character using `push_back()`.
4. Return `ans`.

### Key Concept: String as a Stack

A string can behave like a stack using three operations:

- `push_back(c)` – Adds a character to the end.
- `pop_back()` – Removes the last character.
- `back()` – Accesses the last character.

This works because when a bad pair is encountered, the most recently added character is the one that needs to be removed.

### Key Concept: Case-Insensitive Comparison

We use the `tolower()` function to convert characters to lowercase before comparing them.

```cpp
a != b && tolower(a) == tolower(b)
```

- `a != b` ensures the characters have different cases.
- `tolower(a) == tolower(b)` ensures they represent the same letter.

For example:

```text
'E' != 'e'                  → true
tolower('E') == tolower('e') → true
```

Therefore, `E` and `e` form a bad pair.

## C++ Solution

```cpp
class Solution {
public:
    string makeGood(string s) {
        string ans;

        for (const char c : s) {
            if (!ans.empty() && isBadPair(ans.back(), c))
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }

    bool isBadPair(char a, char b) {
        return a != b && tolower(a) == tolower(b);
    }
};
```

## Example

**Input:**

```text
s = "leEeetcode"
```

**Processing:**

| Current Character | Operation | ans |
|---|---|---|
| l | Push | l |
| e | Push | le |
| E | Remove e | l |
| e | Push | le |
| e | Push | lee |
| t | Push | leet |
| c | Push | leetc |
| o | Push | leetco |
| d | Push | leetcod |
| e | Push | leetcode |

**Output:**

```text
"leetcode"
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity: O(n)**

  We traverse the input string exactly once. Each character is pushed or causes at most one pop operation. Both stack operations take O(1) amortized time.

- **Space Complexity: O(n)**

  In the worst case, no characters are removed, and the resulting string stores all `n` characters.

## Key Takeaways

- A string can be used as a stack without declaring `stack<char>`.
- `back()` helps access the most recently added character.
- `pop_back()` removes the most recently added character.
- `tolower()` enables case-insensitive character comparison.
- Stack-based processing handles cascading adjacent removals naturally.