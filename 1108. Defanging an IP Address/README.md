# 1108. Defanging an IP Address

## Problem
Given a valid IPv4 address, replace every period (`.`) with `[.]` and return the defanged version of the IP address.

## Approach: String Traversal

1. Create an empty string `answer` to store the modified IP address.
2. Traverse the input string character by character using a `for` loop.
3. Check whether the current character is a period (`.`).
   - If yes, append `[.]` to `answer` using `append()`.
   - Otherwise, append the current character using `+=`.
4. Return the modified string.

## C++ Concepts Used

- **String Traversal:** Accessing each character using its index.
- **Conditional Statements:** Checking whether a character is a period.
- **`append()`:** Adding a complete string to another string.
- **`+=` Operator:** Appending a single character to a string.
- **ASCII Value:** The period character `'.'` has ASCII value `46`.

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** O(n) — We traverse the input string once.
- **Space Complexity:** O(n) — We create a new string to store the result.

## Key Learning

A string can be modified by building a new string character by character. We can append either a single character or an entire substring depending on the condition.

**Alternative:** Instead of `int(address[i]) == 46`, we can directly write `address[i] == '.'`, which is more readable.

