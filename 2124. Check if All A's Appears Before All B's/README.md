# LeetCode 2124: Check if All A's Appears Before All B's

## Problem

Given a string `s` consisting only of characters `'a'` and `'b'`, return `true` if every `'a'` appears before every `'b'` in the string.

Otherwise, return `false`.

In other words, the string must not contain a `'b'` followed by an `'a'`.

## Approach

We use **Linear Traversal** to check whether the string follows the required order.

The main observation is:

If all `'a'` characters appear before all `'b'` characters, we should never encounter `'a'` immediately after `'b'`.

### 1. Traverse the String

Start from index `1` because we need to compare each character with its previous character.

```cpp
for(int i = 1; i < static_cast<int>(s.size()); ++i)
```

### 2. Check Consecutive Characters

For every index, compare the current character with the previous character.

```cpp
if(s[i - 1] == 'b' && s[i] == 'a'){
    return false;
}
```

If we encounter `'b'` followed by `'a'`, the required ordering is violated.

We immediately return `false`.

### 3. Return True

If the entire string is traversed without finding this pattern, all `'a'` characters appear before all `'b'` characters.

Therefore, return `true`.

## C++ Solution

```cpp
class Solution {
public:
    bool checkString(string s) {
        for(int i = 1; i < static_cast<int>(s.size()); ++i){
            if(s[i - 1] == 'b' && s[i] == 'a'){
                return false;
            }
        }
        return true;
    }
};
```

## Example

**Example 1:**

Input:
```text
s = "aaabbb"
```

Output:
```text
true
```

Explanation:

All `'a'` characters appear before all `'b'` characters.

**Example 2:**

Input:
```text
s = "abab"
```

Output:
```text
false
```

Explanation:

At index `2`, the current character is `'a'` and the previous character is `'b'`.

This violates the required ordering.

## Complexity Analysis

Let `n` be the length of the string.

**Time Complexity: O(n)**

- We traverse the string once.
- Each iteration performs a constant-time comparison.
- We return early if an invalid pattern is found.

**Space Complexity: O(1)**

- We use only a loop variable and no additional data structures.
- The algorithm uses constant auxiliary space.

## Key Concepts Learned

1. Linear String Traversal
2. Character Comparison
3. Checking Adjacent Elements
4. Early Return Optimization
5. Using `static_cast<int>()` for explicit type conversion