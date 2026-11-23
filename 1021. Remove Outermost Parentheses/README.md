# LeetCode 1021: Remove Outermost Parentheses

## Problem

Given a valid parentheses string `s`, remove the outermost parentheses of every primitive substring and return the resulting string.

A primitive parentheses string is a non-empty valid parentheses string that cannot be split into two non-empty valid parentheses strings.

**Example:**

Input:
```text
s = "(()())(())"
```

Output:
```text
"()()()"
```

Explanation:

- `(()())` → `()()`
- `(())` → `()`

Concatenating the results gives `"()()()"`.

## Approach

### Depth Tracking

We use an integer variable `depth` to track the current nesting level of parentheses.

- When we encounter an opening parenthesis `(`:
  1. Increment `depth`.
  2. If `depth > 1`, append the character to `answer`.
  3. If `depth == 1`, it is an outermost opening parenthesis, so skip it.

- When we encounter a closing parenthesis `)`:
  1. If `depth > 1`, append the character to `answer`.
  2. Decrement `depth`.
  3. If `depth == 1` before decrementing, the character is an outermost closing parenthesis, so skip it.

This ensures that only the inner parentheses are included in the result.

## C++ Solution

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int depth = 0;

        for(char c : s) {
            if(c == '(') {
                depth++;
                if(depth > 1) answer += c;
            }
            else {
                if(depth > 1) answer += c;
                depth--;
            }
        }

        return answer;
    }
};
```

## Example

**Input:**
```text
s = "(()())(())"
```

| Character | Depth | Action |
|---|---:|---|
| `(` | 1 | Skip |
| `(` | 2 | Append |
| `)` | 2 | Append |
| `(` | 2 | Append |
| `)` | 2 | Append |
| `)` | 1 | Skip |
| `(` | 1 | Skip |
| `(` | 2 | Append |
| `)` | 2 | Append |
| `)` | 1 | Skip |

**Output:**
```text
"()()()"
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** `O(n)` – We traverse the string exactly once. Each character is processed in constant time.
- **Space Complexity:** `O(n)` – We use the `answer` string to store the resulting characters. The auxiliary space apart from the output is `O(1)`.

## Key Concepts Learned

- String traversal using range-based loops.
- Tracking nested parentheses using a counter.
- Understanding nesting depth.
- Selectively appending characters to a result string.
- Identifying outermost parentheses without using a stack.