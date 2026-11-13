# Determine if Two Halves of a String Are Alike

## Problem

You are given a string `s` of even length. Split the string into two halves of equal length.

Return `true` if both halves contain the same number of vowels. Otherwise, return `false`.

The vowels are:

```text
a, e, i, o, u
```

Both uppercase and lowercase vowels are considered vowels.

### Example

```text
Input:
s = "book"

Output:
true
```

Because:

```text
First half:  "bo" → 1 vowel (o)
Second half: "ok" → 1 vowel (o)
```

Another example:

```text
Input:
s = "textbook"

Output:
false
```

Because:

```text
First half:  "text" → 1 vowel (e)
Second half: "book" → 2 vowels (o, o)
```

---

## Approach

We count the vowels in both halves of the string using a single counter.

1. Create a helper function `isVowel()` to check whether a character is a vowel.
2. Convert the character to lowercase using `tolower()` so uppercase vowels are also handled.
3. Traverse the first half of the string:
   - If a character is a vowel, increment `count`.
4. Traverse the second half:
   - If a character is a vowel, decrement `count`.
5. If `count == 0`, both halves contain the same number of vowels, so return `true`.
6. Otherwise, return `false`.

### Example

For `s = "book"`:

```text
First half:  "bo"
Second half: "ok"

Initial count = 0

First half:
'b' → consonant → count = 0
'o' → vowel     → count = 1

Second half:
'o' → vowel     → count = 0
'k' → consonant → count = 0

Final count = 0
```

Therefore, the answer is `true`.

---

## Code

```cpp
class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(static_cast<unsigned char>(ch));

        return (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u');
    }

    bool halvesAreAlike(string s) {

        int count = 0;

        for(int i = 0; i < s.size()/2; i++) {
            if(isVowel(s[i])) {
                count++;
            }
        }

        for(int j = s.size()/2; j < s.size(); j++) {
            if(isVowel(s[j])) {
                count--;
            }
        }

        if(count == 0) {
            return true;
        }

        return false;
    }
};
```

---

## Complexity

- **Time Complexity:** `O(n)` — We traverse both halves of the string, covering all `n` characters. Each vowel check takes constant time.
- **Space Complexity:** `O(1)` — We use only a counter and a character variable. No additional data structure is required.

---

## Key Idea

> Instead of maintaining two separate vowel counters, increment the counter for every vowel in the first half and decrement it for every vowel in the second half. If the final count is zero, both halves contain the same number of vowels.