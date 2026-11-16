# LeetCode 1859: Sorting the Sentence

## Problem

A sentence is given as a string `s`, where each word contains a digit at the end representing its original position in the sentence.

The words are separated by single spaces, and the positions start from `1`.

Rearrange the words according to their position numbers and return the reconstructed sentence without the trailing digits.

## Approach

1. Create a vector `word` of size `10` to store the words according to their position numbers. Since the problem allows at most 9 words, indices `1` through `9` are sufficient.
2. Create an empty string `currentWord` to temporarily store the characters of the current word.
3. Initialize `wordCount` to `0` to keep track of the total number of words.
4. Traverse the input string character by character using a range-based `for` loop.
5. For each character:
   - If `isdigit(c)` returns true, the character represents the position of the current word.
   - Convert the digit into an integer using `c - '0'`.
   - Store `currentWord` at the corresponding index in the `word` vector.
   - Clear `currentWord` to prepare for the next word.
   - Increment `wordCount`.
   - If the character is not a digit or a space, append it to `currentWord`.
6. Create an empty string `answer` to construct the final sentence.
7. Iterate from index `1` to `wordCount` and append each word to `answer` in the correct order.
8. Add a space between consecutive words, but not after the last word.
9. Return the reconstructed sentence.

### Key Concept 1: Converting a Digit Character into an Integer

```cpp
word[c - '0'] = currentWord;
```

The expression `c - '0'` converts a numeric character into its corresponding integer.

For example:

| Character | Expression | Integer |
|---|---|---:|
| `'1'` | `'1' - '0'` | 1 |
| `'2'` | `'2' - '0'` | 2 |
| `'5'` | `'5' - '0'` | 5 |

This works because digit characters have consecutive ASCII values.

Therefore, instead of converting the character using a separate function, we can directly subtract `'0'`.

### Key Concept 2: Using a Vector as a Position-Based Storage

```cpp
vector<string> word(10);
```

This creates a vector containing 10 strings, initially empty.

We use the digit at the end of each word as its index.

For example, consider:

```text
is2 sentence4 This1 a3
```

The words are stored as follows:

| Index | Stored Word |
|---:|---|
| 1 | This |
| 2 | is |
| 3 | a |
| 4 | sentence |

This allows us to reconstruct the sentence simply by traversing the vector from index `1` to `wordCount`.

### Key Concept 3: Using `isdigit()`

```cpp
if (isdigit(c))
```

The `isdigit()` function checks whether a character is a numeric digit (`0`–`9`).

It returns true when the character is a digit and false otherwise.

In this problem, encountering a digit indicates that the current word has ended and its position number has been reached.

## C++ Solution

```cpp
class Solution {
public:
    string sortSentence(string s) {
        vector<string> word(10);
        string currentWord = "";
        int wordCount = 0;

        for (char c : s) {
            if (isdigit(c)) {
                word[c - '0'] = currentWord;
                currentWord = "";
                wordCount++;
            }
            else if (c != ' ') {
                currentWord += c;
            }
        }

        string answer = "";

        for (int i = 1; i <= wordCount; i++) {
            answer += word[i];

            if (i < wordCount) {
                answer += " ";
            }
        }

        return answer;
    }
};
```

## Example

**Input:**

```text
s = "is2 sentence4 This1 a3"
```

**Output:**

```text
"This is a sentence"
```

**Explanation:**

First, we traverse the input string and extract each word along with its position number.

The words are stored in the vector according to their positions:

| Position | Word |
|---:|---|
| 1 | This |
| 2 | is |
| 3 | a |
| 4 | sentence |

Next, we traverse the vector from index `1` to `4` and append each word to the result string.

The final reconstructed sentence is:

```text
This is a sentence
```

## Complexity Analysis

- **Time Complexity:** `O(n)` — We traverse the input string once to extract and store the words. We then traverse the vector to construct the final sentence. Both operations take linear time relative to the input size.

- **Space Complexity:** `O(n)` — We use a vector of strings to store the extracted words and an additional string to construct the answer. The total storage required is proportional to the input size.

## Key Takeaways

- A range-based `for` loop (`for (char c : s)`) allows us to traverse a string character by character.
- `isdigit(c)` checks whether a character is a numeric digit.
- Subtracting `'0'` from a digit character converts it into an integer.
- A vector can be used for position-based storage when the required indices are known.
- Clearing a temporary string using `currentWord = ""` allows it to be reused for the next word.
- We can reconstruct a sentence by traversing the storage vector in the required order.
- Checking `i < wordCount` ensures that no unnecessary trailing space is added.

## Conclusion

This solution uses character-by-character traversal and position-based vector storage to rearrange the words without requiring a sorting algorithm.

The key observation is that every word already contains its correct position number. Instead of sorting the words, we directly place each word at its corresponding index and reconstruct the sentence in one final traversal.

This demonstrates how understanding the input structure can eliminate the need for an unnecessary sorting operation.