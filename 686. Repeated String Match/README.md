# LeetCode 686: Repeated String Match

## Problem

Given two strings `a` and `b`, return the minimum number of times you need to repeat string `a` so that string `b` becomes a substring of the repeated string.

If it is impossible for `b` to become a substring, return `-1`.

## Approach

We use **String Concatenation + Substring Search**.

The idea is to repeatedly concatenate string `a` until the resulting string is at least as long as string `b`.

### Steps

1. Initialize `repeated` with string `a`.
2. Initialize `count = 1` because we already have one copy of `a`.
3. Use a `while` loop to append `a` until `repeated.size()` becomes greater than or equal to `b.size()`.
4. Use `find()` to check whether `b` exists inside `repeated`.
5. If found, return the current repetition count.
6. If not found, append `a` one additional time and increment the count.
7. Search again. If found, return the count.
8. Otherwise, return `-1`.

### Why One Extra Repetition?

A substring can start near the end of one copy of `a` and finish in the next copy.

For example:

```text
a = "abcd"
b = "cdabcdab"

Repeated string:
abcdabcdabcd

Substring:
  cdabcdab
```

The extra repetition ensures that we check possible matches crossing the boundary between two consecutive copies.

We don't need unlimited repetitions because a matching substring can have length at most `b.size()` and can cross at most one copy boundary.

## C++ Solution

```cpp
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (repeated.find(b) != string::npos) {
            return count;
        }

        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};
```

## Key Concepts

### 1. String Concatenation

```cpp
repeated += a;
```

The `+=` operator appends the complete string `a` to `repeated`.

Example:

```cpp
string repeated = "abc";
repeated += "abc";

// repeated = "abcabc"
```

### 2. String::find()

```cpp
repeated.find(b)
```

The `find()` function searches for the first occurrence of string `b` inside `repeated`.

It returns:
- The starting index if the substring is found.
- `string::npos` if the substring is not found.

### 3. string::npos

```cpp
if (repeated.find(b) != string::npos)
```

This condition checks whether `b` exists inside `repeated`.

### 4. String Size Comparison

```cpp
while (repeated.size() < b.size())
```

We continue appending `a` until the repeated string is at least as long as `b`.

This is necessary because a shorter string cannot contain a longer substring.

## Example

**Input:**

```text
a = "abcd"
b = "cdabcdab"
```

**Execution:**

| Step | Repeated String | Count |
|---|---|---|
| Initial | abcd | 1 |
| First append | abcdabcd | 2 |
| Second append | abcdabcdabcd | 3 |

Now `repeated.size()` is greater than or equal to `b.size()`.

We check:

```cpp
repeated.find("cdabcdab")
```

The substring is found at index `2`.

**Output:**

```text
3
```

## Complexity Analysis

Let:
- `n` = length of string `a`.
- `m` = length of string `b`.

- **Time Complexity:** O(m + n) for constructing the repeated string, plus the cost of up to two substring searches. The exact search complexity depends on the string-search implementation.
- **Space Complexity:** O(m + n) for storing the repeated string.

## What I Learned

- Repeated string concatenation using `+=`.
- Searching for substrings using `find()`.
- Understanding `string::npos`.
- Using string lengths to determine when to stop concatenating.
- Understanding how substrings can cross concatenation boundaries.
- Finding a mathematical upper bound instead of checking indefinitely.
- Using an additional repetition to handle boundary-crossing matches.