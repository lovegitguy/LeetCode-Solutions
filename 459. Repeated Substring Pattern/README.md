# LeetCode 459: Repeated Substring Pattern

## Problem

Given a string `s`, check whether it can be constructed by taking a substring of it and appending multiple copies of that substring together.

Return `true` if the string can be constructed this way; otherwise, return `false`.

**Example:**

- Input: `s = "abab"`
- Output: `true`
- Explanation: The substring `"ab"` repeated twice produces `"abab"`.

Another example:

- Input: `s = "aba"`
- Output: `false`
- Explanation: No smaller substring can be repeated to construct `"aba"`.

---

## Approach

We use a **String Concatenation + Substring Search** approach.

### 1. Concatenate the String With Itself

First, create a new string `ss` by concatenating `s` with itself.

```cpp
const string ss = s + s;
```

For example:

```cpp
s = "abab"
ss = "abababab"
```

### 2. Remove the First and Last Characters

We use:

```cpp
ss.substr(1, ss.length() - 2)
```

This creates a substring starting from index `1` and containing `ss.length() - 2` characters.

For our example:

```cpp
ss = "abababab"
```

After removing the first and last characters:

```cpp
"bababa"
```

### 3. Search for the Original String

Now search for the original string `s` inside the modified string using `find()`.

```cpp
ss.substr(1, ss.length() - 2).find(s)
```

- If `s` is found, `find()` returns its starting position.
- If `s` is not found, it returns `string::npos`.

The condition:

```cpp
!= string::npos
```

checks whether the original string exists inside the modified concatenated string.

If found, return `true`; otherwise, return `false`.

### Key Concept: String Concatenation Trick

The important observation is that if a string consists of repeated copies of a smaller substring, concatenating it with itself creates overlapping occurrences of the original string.

By removing the first and last characters, we eliminate the original occurrence at position `0` and prevent the occurrence at the very end from being counted.

If another complete occurrence of `s` exists, the string has a repeated substring pattern.

---

## C++ Solution

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const string ss = s + s;

        return ss.substr(1, ss.length() - 2)
                  .find(s) != string::npos;
    }
};
```

---

## Example

**Input:**

```cpp
s = "abab"
```

**Step 1: Concatenate the string**

```cpp
ss = "abababab"
```

**Step 2: Remove the first and last characters**

```cpp
ss.substr(1, ss.length() - 2)
= "bababa"
```

**Step 3: Search for the original string**

```cpp
"bababa".find("abab")
```

The substring `"abab"` is found at index `1`.

Therefore:

```cpp
Output: true
```

---

## Complexity Analysis

Let `n` be the length of the original string.

**Time Complexity: O(n)**

- String concatenation takes O(n).
- Creating the substring takes O(n).
- Finding the original string takes O(n) using an efficient string-search implementation (such as the standard library's typical linear-time implementations).

**Space Complexity: O(n)**

- The concatenated string requires O(2n) space.
- The extracted substring also requires O(n) space.
- Therefore, auxiliary space complexity is O(n).

---

## Key Takeaways

- Learned the string concatenation technique.
- Practiced `substr()` to extract a portion of a string.
- Learned how `find()` searches for a substring.
- Understood `string::npos` as the indicator that a substring was not found.
- Applied a clever string property to solve a pattern-detection problem without explicitly generating every possible substring.