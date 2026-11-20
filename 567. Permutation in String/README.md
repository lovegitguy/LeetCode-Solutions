# LeetCode 567: Permutation in String

## Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, determine whether any substring of `s2` contains exactly the same characters with the same frequencies as `s1`, regardless of their order.

**Example:**

```text
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
```

**Explanation:**

The substring `"ba"` exists in `s2` and is a permutation of `"ab"`.

## Approach

We use **Frequency Counting + Fixed-Size Sliding Window**.

A permutation contains exactly the same characters with the same frequencies. Therefore, instead of generating every possible permutation, we compare character frequencies.

### Step 1: Initialize Frequency Arrays

Create two arrays of size 26:

- `freq1[26]`: Stores the frequency of each character in `s1`.
- `freq2[26]`: Stores the frequency of each character in the current window of `s2`.

We use `character - 'a'` to convert lowercase English letters into indices from 0 to 25.

### Step 2: Count Frequencies in `s1`

Traverse `s1` and update its frequency array.

```cpp
for(int i = 0; i < n; i++) {
    freq1[s1[i] - 'a']++;
}
```

### Step 3: Build the Initial Window

The window size must be equal to the length of `s1`.

Count the frequencies of the first `n` characters of `s2`.

```cpp
for(int i = 0; i < n; i++) {
    freq2[s2[i] - 'a']++;
}
```

Compare both frequency arrays. If all 26 frequencies match, return `true`.

### Step 4: Apply Sliding Window

Move the window one position to the right.

For every movement:

1. Remove the outgoing character.
2. Add the incoming character.
3. Compare the two frequency arrays.

```cpp
freq2[s2[i - n] - 'a']--;
freq2[s2[i] - 'a']++;
```

**Why `i - n`?**

The current window has size `n`. When the incoming character is at index `i`, the outgoing character is exactly `n` positions behind it.

This allows us to update the window without recounting all its characters.

### Step 5: Return the Result

If any window has matching frequencies, return `true`.

If no window matches after traversing `s2`, return `false`.

## C++ Solution

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {};
        int freq2[26] = {};

        int n = s1.size();
        int m = s2.size();

        if(m < n) return false;

        for(int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
        }

        for(int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                break;
            }

            if(i == 25) return true;
        }

        for(int i = n; i < m; i++) {
            freq2[s2[i - n] - 'a']--;
            freq2[s2[i] - 'a']++;

            bool match = true;

            for(int j = 0; j < 26; j++) {
                if(freq1[j] != freq2[j]) {
                    match = false;
                    break;
                }
            }

            if(match) return true;
        }

        return false;
    }
};
```

## Example

**Input:**

```text
s1 = "ab"
s2 = "eidbaooo"
```

**Initial Frequency Comparison:**

- `s1`: `"ab"`
- Initial window: `"ei"`
- Frequencies do not match.

**Sliding Window Execution:**

| Window | Outgoing | Incoming | Match? |
|---|---|---|---|
| ei | - | - | No |
| id | e | d | No |
| db | i | b | No |
| ba | d | a | Yes |

**Output:**

```text
true
```

The window `"ba"` contains the same character frequencies as `"ab"`.

## Complexity Analysis

Let:
- `n` = length of `s1`
- `m` = length of `s2`

**Time Complexity:**

- Building `freq1`: `O(n)`
- Building the initial window: `O(n)`
- Sliding through `s2`: `O(m × 26)`

Total:

`O(n + 26m) = O(n + m)`

Since the alphabet contains a fixed 26 lowercase English letters, comparing frequency arrays takes constant time.

**Space Complexity:**

`O(26 + 26) = O(1)`

We use two fixed-size frequency arrays, independent of input length.

## Key Concepts Learned

- Frequency counting using arrays.
- Character-to-index mapping using `character - 'a'`.
- Fixed-size Sliding Window.
- Tracking outgoing and incoming elements.
- Comparing frequency arrays.
- Optimizing repeated calculations by maintaining a running window.