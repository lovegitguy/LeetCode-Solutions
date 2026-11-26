# LeetCode 791: Custom Sort String

## Problem
Given two strings `order` and `s`, rearrange the characters of `s` so that characters appearing in `order` follow the same relative ordering.

## Approach
- Create a frequency array of size 26 to count character occurrences.
- Traverse `order` and append each character according to its frequency.
- Reset its frequency to zero after processing.
- Append remaining characters in alphabetical order.

## C++ Solution
```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string result;
        result.reserve(s.size());

        for (char c : order) {
            int index = c - 'a';
            result.append(freq[index], c);
            freq[index] = 0;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                result.append(freq[i], static_cast<char>('a' + i));
            }
        }

        return result;
    }
};
```

## Complexity Analysis
- **Time Complexity:** O(|s| + |order| + 26).
- **Space Complexity:** O(26) auxiliary space, excluding the output string.