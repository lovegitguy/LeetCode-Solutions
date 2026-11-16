# LeetCode 1614: Maximum Nesting Depth of the Parentheses

## Problem

Given a valid parentheses string `s`, return the maximum nesting depth of the parentheses.

The nesting depth is the maximum number of parentheses that are open at the same time.

For example:

- `()` has a depth of `1`.
- `(())` has a depth of `2`.
- `((()))` has a depth of `3`.

## Approach

1. Initialize an integer variable `current_depth` to `0` to keep track of the current nesting depth.
2. Initialize another integer variable `max_depth` to `0` to store the maximum nesting depth encountered so far.
3. Traverse the string character by character using a range-based `for` loop.
4. For each character:
   - If the character is `'('`, increment `current_depth` by `1` because a new opening parenthesis increases the nesting depth.
   - Update `max_depth` using `max(max_depth, current_depth)` to maintain the maximum depth encountered so far.
   - If the character is `')'`, decrement `current_depth` by `1` because a closing parenthesis completes an open pair.
5. After traversing the entire string, return `max_depth`.

## Key Concept 1: Tracking the Current Depth

```cpp
if (c == '(') {
    current_depth += 1;
}
else if (c == ')') {
    current_depth -= 1;
}
```

The current depth represents the number of opening parentheses that have not yet been matched with closing parentheses.

- Every opening parenthesis increases the depth.
- Every closing parenthesis decreases the depth.

For example:

```text
s = "(1+(2*3)+((8)/4))+1"
```

The depth changes as parentheses are encountered:

| Parenthesis encountered | Current Depth |
|---|---:|
| `(` | 1 |
| `(` | 2 |
| `)` | 1 |
| `(` | 2 |
| `(` | 3 |
| `)` | 2 |
| `)` | 1 |
| `)` | 0 |

The maximum depth is `3`.

## Key Concept 2: Maintaining the Maximum Value

```cpp
max_depth = max(max_depth, current_depth);
```

The `max()` function returns the larger of two values.

Here:
- `max_depth` represents the highest depth found so far.
- `current_depth` represents the current nesting depth.

Whenever we encounter an opening parenthesis, we update the maximum depth.

This ensures that even if the current depth decreases later, we don't lose the previously recorded maximum.

## C++ Solution

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int current_depth = 0;
        int max_depth = 0;

        for (char c : s) {
            if (c == '(') {
                current_depth += 1;
                max_depth = max(max_depth, current_depth);
            }
            else if (c == ')') {
                current_depth -= 1;
            }
        }

        return max_depth;
    }
};
```

## Example

**Input:**

```text
s = "(1+(2*3)+((8)/4))+1"
```

**Output:**

```text
3
```

**Explanation:**

The maximum nesting occurs when three opening parentheses are active simultaneously.

The depth changes as follows:

| Character | Current Depth | Maximum Depth |
|---|---:|---:|
| `(` | 1 | 1 |
| `(` | 2 | 2 |
| `)` | 1 | 2 |
| `(` | 2 | 2 |
| `(` | 3 | 3 |
| `)` | 2 | 3 |
| `)` | 1 | 3 |
| `)` | 0 | 3 |

Therefore, the maximum nesting depth is `3`.

## Complexity Analysis

- **Time Complexity:** `O(n)` — We traverse the string exactly once, and each character requires constant-time operations.

- **Space Complexity:** `O(1)` — We use only two integer variables, regardless of the input string's length.

## Key Takeaways

- A counter can track the current nesting depth of parentheses.
- Opening parentheses increase the depth, while closing parentheses decrease it.
- `max()` helps maintain the maximum value encountered during traversal.
- We don't need a stack because the problem only asks for the maximum depth, not matching or storing individual parentheses.
- Range-based `for` loops provide a simple way to traverse strings character by character.

## Conclusion

This solution uses a simple counter-based approach to calculate the maximum nesting depth of a valid parentheses string.

By increasing the counter for every opening parenthesis, decreasing it for every closing parenthesis, and maintaining the maximum value, we can solve the problem in a single traversal with constant extra space.