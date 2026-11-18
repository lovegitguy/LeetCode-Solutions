c# LeetCode: Minimum Changes to Make Alternating Binary String (minChanges)

## Problem
Given a binary string `s`, divide it into consecutive pairs of characters. Each pair should contain identical characters.

In one operation, we can change any character from `'0'` to `'1'` or from `'1'` to `'0'`.

Return the minimum number of changes required to make every pair contain identical characters.

## Approach
We can solve this problem using a simple **Greedy Approach**.

1. Initialize an integer variable `ans = 0` to count the required changes.
2. Traverse the string using a loop with an increment of `2` (`i += 2`), because we need to examine consecutive pairs.
3. Compare the characters at positions `i` and `i + 1`.
4. If both characters are different, one of them must be changed to make the pair identical. Increment `ans`.
5. Return `ans`.

### Key Concept: Pairwise Traversal

Instead of checking every character individually, we process the string in pairs:

- `(s[0], s[1])`
- `(s[2], s[3])`
- `(s[4], s[5])`

If both characters in a pair are already identical, no changes are needed.

If they are different, exactly one change is sufficient.

## C++ Solution

```cpp
class Solution {
 public:
  int minChanges(string s) {
    int ans = 0;

    for (int i = 0; i + 1 < s.length(); i += 2)
      if (s[i] != s[i + 1])
        ++ans;

    return ans;
  }
};
```

## Example

**Input:**
```text
s = "1001"
```

**Output:**
```text
2
```

**Explanation:**

We divide the string into pairs:

| Pair | Comparison | Changes Required |
|---|---|---|
| `"10"` | Different characters | 1 |
| `"01"` | Different characters | 1 |

Total changes = 1 + 1 = **2**.

Therefore, the minimum number of changes required is `2`.

## Complexity Analysis

**Time Complexity: O(n)**

- We traverse the string once.
- Each pair requires only one comparison.
- Therefore, the overall time complexity is O(n).

**Space Complexity: O(1)**

- We use only one additional integer variable `ans`.
- No extra data structures are required.

## Key Takeaway

When a problem requires processing consecutive pairs, incrementing the loop variable by `2` (`i += 2`) allows us to process each pair directly without unnecessary iterations.

This is a simple example of greedy thinking: make the minimum required change independently for each pair.