# LeetCode 165: Compare Version Numbers

## Problem

Given two version strings, `version1` and `version2`, compare them and return:

- `-1` if `version1` is smaller than `version2`.
- `1` if `version1` is greater than `version2`.
- `0` if both versions are equal.

Each version consists of one or more revision numbers separated by dots (`.`).

A revision number is interpreted as an integer, meaning leading zeros should be ignored.

If one version has fewer revisions, treat its missing revisions as `0`.

## Approach

We use **Two Pointers** to traverse both version strings simultaneously and compare their revision numbers one by one.

### Steps

1. Calculate the lengths of both version strings using `size()`.
2. Initialize two pointers, `i` and `j`, at index `0`.
3. Use a `while` loop that continues as long as either pointer has not reached the end of its respective string.
4. Create two empty strings, `answer1` and `answer2`, to store the current revision numbers.
5. Extract the current revision from each version string by traversing until a dot (`.`) or the end of the string is reached.
6. Convert the extracted revision strings into integers using `stoi()`.
   - If a revision string is empty, treat it as `0`.
   - This also handles missing revisions and leading zeros.
7. Compare the two integer values:
   - If `rev1 < rev2`, return `-1`.
   - If `rev1 > rev2`, return `1`.
   - Otherwise, continue to the next revision.
8. Skip the dot (`.`) in both strings if present.
9. If all revision numbers are equal, return `0`.

## C++ Solution

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int i = 0;
        int j = 0;

        while (i < m || j < n) {
            string answer1 = "";
            while (i < m && version1[i] != '.') {
                answer1 += version1[i];
                i++;
            }

            string answer2 = "";
            while (j < n && version2[j] != '.') {
                answer2 += version2[j];
                j++;
            }

            int rev1 = answer1.empty() ? 0 : stoi(answer1);
            int rev2 = answer2.empty() ? 0 : stoi(answer2);

            if (rev1 < rev2) return -1;
            if (rev1 > rev2) return 1;

            if (i < m && version1[i] == '.') i++;
            if (j < n && version2[j] == '.') j++;
        }

        return 0;
    }
};
```

## Example

**Input:**

```cpp
version1 = "1.01"
version2 = "1.001"
```

**Output:**

```cpp
0
```

**Explanation:**

We compare the revision numbers one by one:

| Revision | version1 | version2 |
|---|---:|---:|
| 1 | 1 | 1 |
| 2 | 01 = 1 | 001 = 1 |

Both versions have equal revision numbers, so we return `0`.

### Another Example

**Input:**

```cpp
version1 = "1.2"
version2 = "1.10"
```

**Output:**

```cpp
-1
```

**Explanation:**

- First revision: `1 == 1`.
- Second revision: `2 < 10`.

Therefore, `version1` is smaller than `version2`.

## Complexity Analysis

Let `m` be the length of `version1` and `n` be the length of `version2`.

- **Time Complexity: O(m + n)** — Both strings are traversed once. Each character is processed a constant number of times.
- **Space Complexity: O(m + n)** — The temporary strings used to store revision numbers can collectively hold up to the characters of both input strings in the worst case.

## Key Concepts Learned

- Two Pointers
- String Traversal
- Extracting substrings using character-by-character traversal
- `stoi()` — Converting a numeric string into an integer
- `empty()` — Checking whether a string is empty
- Ternary Operator (`condition ? value1 : value2`)
- Handling leading zeros
- Handling missing revisions by treating them as zero
- Comparing numeric values instead of lexicographical string values