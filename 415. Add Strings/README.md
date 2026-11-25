# LeetCode 415: Add Strings

## Problem

Given two non-negative integers represented as strings `num1` and `num2`, return their sum as a string.

You must not convert the input strings directly into integers or use any built-in BigInteger library.

## Approach

We use **Digit-by-Digit Addition**, similar to how we perform addition manually.

Instead of converting the strings into integers, we process their digits from right to left.

### Steps

1. Initialize two pointers:
   - `i` points to the last digit of `num1`.
   - `j` points to the last digit of `num2`.

2. Initialize `count = 0` to store the carry.

3. Run a loop while:
   - `i >= 0`, meaning digits remain in `num1`.
   - `j >= 0`, meaning digits remain in `num2`.
   - `count > 0`, meaning a carry still needs to be processed.

4. Calculate the sum:
   - Start with the carry.
   - Add the current digit from `num1`, if available.
   - Add the current digit from `num2`, if available.

5. Extract the digit using `sum % 10` and append it to `result`.

6. Update the carry using `sum / 10`.

7. Since digits are processed from right to left, reverse the result before returning it.

## C++ Solution

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int count = 0;
        string result;

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || count > 0) {
            int sum = count;

            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }

            result.push_back((sum % 10) + '0');
            count = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```

## Key Concepts

### 1. Character to Integer Conversion

```cpp
num1[i] - '0'
```

Characters representing digits have consecutive ASCII values.

Subtracting `'0'` converts a numeric character into its integer value.

For example:

```cpp
'7' - '0' = 7
```

### 2. Extracting the Last Digit

```cpp
sum % 10
```

The modulo operator extracts the last digit of the sum.

For example:

```cpp
17 % 10 = 7
```

### 3. Calculating Carry

```cpp
count = sum / 10;
```

Integer division gives us the carry.

For example:

```cpp
17 / 10 = 1
```

### 4. Why Reverse the Result?

We process digits from right to left, so the resulting digits are initially stored in reverse order.

For example:

```text
Actual result:  1234
Stored result:  4321
```

Therefore, we use:

```cpp
reverse(result.begin(), result.end());
```

## Example

**Input:**

```text
num1 = "456"
num2 = "77"
```

**Digit-by-digit execution:**

| Step | Calculation | Digit added | Carry |
|---|---|---|---|
| 1 | 6 + 7 = 13 | 3 | 1 |
| 2 | 5 + 7 + 1 = 13 | 3 | 1 |
| 3 | 4 + 1 = 5 | 5 | 0 |

Result before reversing:

```text
335
```

Result after reversing:

```text
533
```

**Output:**

```text
"533"
```

## Complexity Analysis

Let `n` be the length of `num1` and `m` be the length of `num2`.

- **Time Complexity:** O(max(n, m)) — each digit is processed once, followed by reversing the result.
- **Space Complexity:** O(max(n, m)) — the result string stores the sum.

## What I Learned

- Performing arithmetic directly on numeric strings.
- Traversing strings from right to left using indices.
- Converting digit characters into integers using `'0'`.
- Using modulo and integer division to extract digits and calculate carry.
- Handling strings of different lengths.
- Using `push_back()` to construct a result string.
- Using `reverse()` to restore the correct digit order.
- Understanding how the carry condition keeps the loop running even after both strings are exhausted.