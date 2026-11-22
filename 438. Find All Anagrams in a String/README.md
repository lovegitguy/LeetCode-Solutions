# LeetCode 438: Find All Anagrams in a String

## Problem

Given two strings `s` and `p`, find all the starting indices of `p`'s anagrams in `s`.

An anagram is a word formed by rearranging the characters of another word, using exactly the same characters with the same frequencies.

Return the starting indices of all anagrams of `p` in `s`.

## Approach

We use the **Sliding Window technique with Frequency Arrays**.

Instead of generating every possible substring and sorting it to check whether it is an anagram, we maintain character frequencies using two arrays.

### 1. Handle the Edge Case

If the length of `p` is greater than the length of `s`, an anagram cannot exist.

```cpp
if(p.size() > s.size()){
    return {};
}
```

### 2. Create Frequency Arrays

We create two arrays of size 26 because the problem contains lowercase English letters.

- `pFreq`: Stores the frequency of each character in `p`.
- `windowFreq`: Stores the frequency of each character in the current window of `s`.

```cpp
vector<int> pFreq(26, 0);
vector<int> windowFreq(26, 0);
```

We use `c - 'a'` to convert a character into an index between 0 and 25.

### 3. Build the Frequency Arrays

First, calculate the character frequencies of `p`.

Then, calculate the frequencies of the first window of `s`, whose size is equal to `p.size()`.

```cpp
for(char c : p){
    pFreq[c - 'a']++;
}

for(int i = 0; i < p.size(); i++){
    windowFreq[s[i] - 'a']++;
}
```

### 4. Check the First Window

If both frequency arrays are equal, the first window is an anagram of `p`.

```cpp
if(pFreq == windowFreq){
    ans.push_back(0);
}
```

### 5. Slide the Window

Instead of rebuilding the frequency array for every substring, we update the existing window.

For every movement:

- Remove the character that leaves the window.
- Add the new character entering the window.
- Compare the updated frequency array with `pFreq`.

```cpp
for(int i = 1; i <= s.size() - p.size(); i++){

    windowFreq[s[i - 1] - 'a']--;
    windowFreq[s[i + p.size() - 1] - 'a']++;

    if(pFreq == windowFreq){
        ans.push_back(i);
    }
}
```

This allows us to move the window in constant time for frequency updates.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.size() > s.size()){
            return {};
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for(char c : p){
            pFreq[c - 'a']++;
        }

        for(int i = 0; i < p.size(); i++){
            windowFreq[s[i] - 'a']++;
        }

        vector<int> ans;

        if(pFreq == windowFreq){
            ans.push_back(0);
        }

        for(int i = 1; i <= s.size() - p.size(); i++){

            windowFreq[s[i - 1] - 'a']--;
            windowFreq[s[i + p.size() - 1] - 'a']++;

            if(pFreq == windowFreq){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

## Example

**Input:**
```text
s = "cbaebabacd"
p = "abc"
```

**Output:**
```text
[0, 6]
```

**Explanation:**

The length of `p` is 3, so we examine windows of size 3.

| Window | Starting Index | Anagram? |
|---|---:|---|
| cba | 0 | Yes |
| bae | 1 | No |
| aeb | 2 | No |
| eba | 3 | No |
| bab | 4 | No |
| aba | 5 | No |
| bac | 6 | Yes |
| acd | 7 | No |

The anagrams are `"cba"` and `"bac"`.

Therefore, the answer is `[0, 6]`.

## Complexity Analysis

Let:
- `n` = length of `s`
- `m` = length of `p`

**Time Complexity: O(n + 26 × n) = O(n)**

- Building the frequency array of `p`: O(m)
- Building the initial window frequency: O(m)
- Sliding the window: O(n)
- Comparing two frequency arrays: O(26), which is constant.

Therefore, the overall time complexity is **O(n + m)**.

**Space Complexity: O(1)**

We use two frequency arrays of fixed size 26. The auxiliary space remains constant regardless of input size. (The output array is excluded.)

## Key Concepts Learned

1. Sliding Window Technique
2. Fixed-size Sliding Window
3. Frequency Arrays
4. Character-to-index conversion using `c - 'a'`
5. Incremental updates instead of recalculating frequencies
6. Comparing frequency arrays to identify anagrams