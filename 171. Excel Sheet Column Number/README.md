# LeetCode 171: Excel Sheet Column Number

## Problem

Given a string `columnTitle` that represents an Excel column title, return its corresponding column number.

Excel columns follow a pattern similar to a number system, but instead of starting from `0`, the letters start from `1`.

Examples:

- A = 1
- B = 2
- ...
- Z = 26
- AA = 27
- AB = 28
- AZ = 52
- BA = 53

## Approach

We use a **Base-26 Number System** approach to convert the Excel column title into its corresponding integer.

Unlike a normal positional number system, Excel columns use values from `1` to `26` instead of `0` to `25`.

### Steps

1. Initialize a `long long` variable `correspondingNumber = 0` to store the result.
2. Traverse each character in `columnTitle` using a range-based for loop.
3. Convert the current character into its corresponding numerical value using:

   `val = c - 'A' + 1`

   For example:
   - A = 1
   - B = 2
   - Z = 26

4. Update the result using:

   `correspondingNumber = correspondingNumber * 26 + val`

5. Repeat this process for every character.
6. Return the final result after converting it to an integer using `static_cast<int>()`.

### Key Concept: Base-26 Positional Number System

In a positional number system, every new digit shifts the previous value one position to the left.

For example, consider `AB`:

- A = 1
- B = 2

Calculation:

`1 * 26 + 2 = 28`

Therefore, `AB = 28`.

## C++ Solution

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long correspondingNumber = 0;

        for (char c : columnTitle) {
            int val = c - 'A' + 1;
            correspondingNumber = correspondingNumber * 26 + val;
        }

        return static_cast<int>(correspondingNumber);
    }
};
```

## Example

**Input:**

```cpp
columnTitle = "ZY"
```

**Output:**

```cpp
701
```

**Explanation:**

We process each character from left to right.

| Character | Value | Calculation | Result |
|---|---:|---|---:|
| Z | 26 | 0 * 26 + 26 | 26 |
| Y | 25 | 26 * 26 + 25 | 701 |

Therefore, the corresponding Excel column number is `701`.

## Complexity Analysis

Let `n` be the length of `columnTitle`.

- **Time Complexity: O(n)** — We traverse the string exactly once, performing constant-time operations for each character.
- **Space Complexity: O(1)** — We use only a fixed number of variables regardless of the input size.

## Key Concepts Learned

- Base-26 Number System
- Positional Number Systems
- Range-Based For Loop
- ASCII Character Arithmetic
- Character-to-Integer Conversion
- `long long` for intermediate calculations
- `static_cast<int>()` for explicit type conversion