# LeetCode 2390: Removing Stars From a String

## Problem

You are given a string `s` containing lowercase English letters and `*` characters.

For every `*`, perform the following operation:

- Remove the closest non-star character to its left.
- Remove the `*` itself.

Continue until all stars have been removed and return the resulting string.

The input is guaranteed to allow all operations.

**Example:**

```text
Input:  s = "leet**cod*e"
Output: "lecoe"
```

**Explanation:**

- `"leet**cod*e"` → First `*` removes `t`.
- The second `*` removes `e`.
- The remaining `*` removes `d`.
- The resulting string is `"lecoe"`.

## Approach

We use a **String as a Stack** to efficiently remove characters.

The idea is to maintain a string `answer` that stores all characters that have not been removed.

1. Initialize an empty string `answer`.
2. Traverse the input string character by character.
3. For each character `c`:
   - If `c` is `'*'`, remove the most recently added character using `pop_back()`.
   - Otherwise, add the current character using `push_back(c)`.
4. Return `answer`.

### Key Concept: String as a Stack

A string can behave like a stack using three operations:

- `push_back(c)` – Adds a character to the end.
- `pop_back()` – Removes the last character.
- `back()` – Accesses the last character.

This works because the closest non-star character to the left is always the most recently added character that has not already been removed.

### Key Concept: LIFO (Last In, First Out)

A stack follows the LIFO principle.

The last character added is the first character removed.

For example:

```text
Input: "abc*d"

Push a → a
Push b → ab
Push c → abc
*     → ab
Push d → abd
```

The `*` removes `c` because it is the most recently added character.

## C++ Solution

```cpp
class Solution {
public:
    string removeStars(string s) {
        string answer = "";

        for(char c : s) {
            if(c == '*') {
                answer.pop_back();
            }
            else {
                answer.push_back(c);
            }
        }

        return answer;
    }
};
```

## Example

**Input:**

```text
s = "leet**cod*e"
```

**Processing:**

| Character | Operation | answer |
|---|---|---|
| l | Push | l |
| e | Push | le |
| e | Push | lee |
| t | Push | leet |
| * | Remove t | lee |
| * | Remove e | le |
| c | Push | lec |
| o | Push | leco |
| d | Push | lecod |
| * | Remove d | leco |
| e | Push | lecoe |

**Output:**

```text
"lecoe"
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity: O(n)**

  We traverse the input string exactly once. Each character is processed with one `push_back()` or `pop_back()` operation, both O(1) amortized.

- **Space Complexity: O(n)**

  In the worst case, the string contains no stars, so `answer` stores all `n` characters.

## Key Takeaways

- A string can be used as a stack without declaring `stack<char>`.
- `push_back()` adds an element to the end.
- `pop_back()` removes the most recently added element.
- The LIFO principle helps solve problems involving the closest previous element.
- Always ensure a valid character exists before calling `pop_back()`. The problem guarantees this condition for every `*`.