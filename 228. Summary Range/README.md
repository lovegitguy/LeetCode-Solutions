# LeetCode 228: Summary Ranges

## Problem

You are given a sorted array of unique integers.

Return the smallest sorted list of ranges that covers all the numbers in the array exactly.

Each range should be represented as:

- `"a"` if the range contains only one number.
- `"a->b"` if the range contains multiple consecutive numbers.

## Approach

We use a **Single Pass Traversal** to identify consecutive sequences.

1. Iterate through the array using index `i`.
2. Store the current number as the beginning of a range.
3. Continue moving forward while the next number is exactly one greater than the current number.
4. Once the consecutive sequence ends, store the last number as the ending of the range.
5. If the beginning and ending are equal, add only that number to the answer.
6. Otherwise, construct a range using `"begin->end"`.

The important part is the `while` loop, which skips all numbers belonging to the current consecutive range.

## Key Concept: Consecutive Sequence Detection

Two numbers are consecutive when:

\[
nums[i+1] = nums[i] + 1
\]

Instead of checking every possible range separately, we extend the current range until this condition becomes false.

This allows us to process the entire array in one traversal.

## C++ Solution

```cpp
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;

    for (int i = 0; i < nums.size(); ++i) {
      const int begin = nums[i];

      while (i + 1 < nums.size() &&
             nums[i] == nums[i + 1] - 1)
        ++i;

      const int end = nums[i];

      if (begin == end)
        ans.push_back(to_string(begin));
      else
        ans.push_back(to_string(begin) + "->" + to_string(end));
    }

    return ans;
  }
};
```

## Example

**Input:**

```text
nums = [0,1,2,4,5,7]
```

**Output:**

```text
["0->2","4->5","7"]
```

**Explanation:**

We identify three ranges:

| Range | Explanation |
|---|---|
| `[0,1,2]` | Consecutive numbers → `"0->2"` |
| `[4,5]` | Consecutive numbers → `"4->5"` |
| `[7]` | Single number → `"7"` |

The final answer is:

```text
["0->2", "4->5", "7"]
```

## Complexity Analysis

Let `n` be the number of elements in the input array.

**Time Complexity:**

\[
O(n)
\]

Although there is a nested `while` loop, every element is visited at most once by the traversal.

**Space Complexity:**

\[
O(1)
\]

Auxiliary space is constant, excluding the output vector.

## Key Takeaways

- A single traversal can identify multiple consecutive ranges.
- Use a `while` loop to extend the current range.
- Be careful with index boundaries: `i + 1 < nums.size()`.
- `to_string()` converts integers into strings.
- Not every nested loop results in quadratic time complexity.
