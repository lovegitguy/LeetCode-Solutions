# LeetCode 824: Goat Latin

## Problem

Given a sentence consisting of words separated by spaces, convert every word into Goat Latin according to these rules:

1. If a word begins with a vowel (`a`, `e`, `i`, `o`, `u`), append `"ma"` to the end.
2. If a word begins with a consonant, remove its first character and append it to the end, then append `"ma"`.
3. Append a number of `'a'` characters equal to the word's position in the sentence (starting from 1).

Return the converted sentence.

## Approach

We use `stringstream` to extract words from the sentence one by one.

For every word:

1. Store its first character in `first`.
2. Check whether the first character is a vowel.
3. If it is a consonant:
   - Remove the first character using `substr(1)`.
   - Append the original first character to the end.
4. Append `"ma"` to the word.
5. Append `'a'` repeatedly according to the word's position.
6. Add the transformed word to the result, inserting a space between words.

We use `count` to track the position of each word.

## Key Concept: stringstream

`stringstream` allows us to process a string as a stream of words.

```cpp
stringstream ss(sentence);

while (ss >> word) {
    // Process each word
}
```

The extraction operator `>>` automatically skips whitespace and extracts the next word.

## C++ Solution

```cpp
class Solution {
public:
    string toGoatLatin(string sentence) {
        string word;
        stringstream ss(sentence);
        string result = "";
        int count = 1;

        while (ss >> word) {
            char first = word[0];

            if (first == 'a' || first == 'e' || first == 'i' ||
                first == 'o' || first == 'u' ||
                first == 'A' || first == 'E' || first == 'I' ||
                first == 'O' || first == 'U') {

            }
            else {
                word = word.substr(1) + word[0];
            }

            word += "ma";

            for (int i = 0; i < count; i++) {
                word += 'a';
            }

            if (!result.empty()) {
                result += " ";
            }

            result += word;
            count++;
        }

        return result;
    }
};
```

## Example

**Input:**
```text
sentence = "I speak Goat Latin"
```

**Output:**
```text
"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
```

**Explanation:**

| Original word | Transformation |
|---|---|
| I | I + ma + a |
| speak | peaks + ma + aa |
| Goat | oatG + ma + aaa |
| Latin | atinL + ma + aaaa |

The number of appended `'a'` characters increases with each word's position.

## Complexity Analysis

Let:
- `n` be the number of characters in the sentence.
- `w` be the number of words.

- **Time Complexity:** \(O(n + w^2)\) with the repeated string appending in the implementation. The total number of appended `'a'` characters is \(1 + 2 + \dots + w = O(w^2)\).
- **Auxiliary Space Complexity:** \(O(n + w)\) for the stream, words, and resulting sentence, including output storage.
