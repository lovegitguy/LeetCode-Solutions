# 1662. Check If Two String Arrays Are Equivalent

## Problem

You are given two string arrays, `word1` and `word2`.

Each array contains multiple strings. Concatenate all the strings in each array to form two complete strings.

Return `true` if both resulting strings are equal. Otherwise, return `false`.

### Example

```text
Input:
word1 = ["ab", "c"]
word2 = ["a", "bc"]

Output:
true
```

Because:

```text
word1 → "ab" + "c"  = "abc"
word2 → "a"  + "bc" = "abc"
```

Both resulting strings are equal.

Another example:

```text
Input:
word1 = ["a", "cb"]
word2 = ["ab", "c"]

Output:
false
```

Because:

```text
word1 → "acb"
word2 → "abc"
```

The resulting strings are different.

---

## Approach

We create two empty strings and concatenate all the elements of their respective arrays.

1. Initialize two empty strings, `c` and `d`.
2. Traverse `word1`:
   - Append every string to `c` using `+=`.
3. Traverse `word2`:
   - Append every string to `d` using `+=`.
4. Compare both complete strings using the equality operator (`==`).
5. If both strings are equal, return `true`; otherwise, return `false`.

### Example

For:

```text
word1 = ["ab", "c"]
word2 = ["a", "bc"]
```

**First array traversal:**

```text
c = ""

c += "ab" → "ab"
c += "c"  → "abc"
```

**Second array traversal:**

```text
d = ""

d += "a"  → "a"
d += "bc" → "abc"
```

**Comparison:**

```text
c == d

"abc" == "abc" → true
```

Therefore, the answer is `true`.

---

## Code

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string c = "";
        string d = "";

        for(int i = 0; i < word1.size(); i++) {
            c += word1[i];
        }

        for(int j = 0; j < word2.size(); j++) {
            d += word2[j];
        }

        if(c == d) {
            return true;
        }

        return false;
    }
};
```

---

## Complexity

Let `n` be the total number of characters across both arrays.

- **Time Complexity:** `O(n)` — We concatenate all characters from both arrays and compare the resulting strings.
- **Space Complexity:** `O(n)` — We create two additional strings to store the concatenated results.

---

## Key Idea

> Concatenate all strings in each array separately, then compare the two resulting strings using `==`. The original division of characters into individual strings does not matter; only the final character sequences matter.
