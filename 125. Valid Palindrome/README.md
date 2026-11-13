# 125. Valid Palindrome

## Approach: Filtering + Two String Comparison

### Intuition
A string is a palindrome if it reads the same forward and backward.

However, the problem requires us to:
- Ignore all non-alphanumeric characters.
- Ignore differences between uppercase and lowercase letters.

To handle this, we first create a cleaned string containing only lowercase alphanumeric characters. Then we reverse it and compare it with the original cleaned string.

### Algorithm
1. Initialize an empty string `answer`.
2. Traverse the input string character by character.
3. Use `isalnum()` to check whether the current character is a letter or digit.
4. If it is alphanumeric, convert it to lowercase using `tolower()` and append it to `answer`.
5. Create a copy of `answer` called `reversedanswer`.
6. Reverse `answer` using `reverse()`.
7. Compare both strings:
   - If they are equal, return `true`.
   - Otherwise, return `false`.

### C++ Concepts Used
- `isalnum()` – Checks whether a character is alphanumeric.
- `tolower()` – Converts a character to lowercase.
- `reverse()` – Reverses a string.
- `push_back` / `+=` – Appends characters to a string.
- `unsigned char` – Ensures safe character handling when passing characters to character-classification functions.
- String comparison using `==`.

### Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** O(n)
  - Filtering the string takes O(n).
  - Copying and reversing the string takes O(n).
  - Comparing both strings takes O(n).

- **Space Complexity:** O(n)
  - We create two additional strings proportional to the input size.

### Key Learning
This problem demonstrates how preprocessing a string can simplify a problem.

Instead of handling uppercase letters, lowercase letters, spaces, and punctuation separately during palindrome checking, we normalize the string first and then perform a straightforward comparison.
