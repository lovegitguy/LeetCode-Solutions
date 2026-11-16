# LeetCode 2243: Calculate Digit Sum of a String

## Problem

You are given a string `s` consisting of digits and an integer `k`.

Repeatedly perform the following operation until the length of `s` is less than or equal to `k`:

1. Divide the string into consecutive groups of size `k`. The final group may contain fewer than `k` characters.
2. Calculate the sum of the digits in each group.
3. Replace each group with its corresponding digit sum and concatenate the results to form a new string.

Return the final string after performing all the operations.

## Approach

1. Use a `while` loop that continues as long as `s.size() > k`. This ensures that the operation is repeated until the string length becomes less than or equal to `k`.
2. Inside the `while` loop, create a vector of strings named `answer` to store the digit sums of individual groups.
3. Use a `for` loop with `i += k` to divide the string into consecutive groups of size `k`.
4. For each group:
   - Initialize `current_sum` to `0`.
   - Use an inner `for` loop to traverse the current group.
   - The condition `j < s.size()` prevents accessing characters outside the string.
   - The condition `j < i + k` ensures that we process at most `k` characters in the current group.
   - Convert each character into an integer using `s[j] - '0'` and add it to `current_sum`.
5. Convert the calculated sum into a string using `to_string(current_sum)` and store it in the `answer` vector using `push_back()`.
6. After processing all groups, clear the original string by assigning an empty string to `s`.
7. Traverse the `answer` vector using a range-based `for` loop and concatenate all the group sums into `s`.
8. The `while` loop repeats the process using the newly constructed string.
9. Once the length of `s` becomes less than or equal to `k`, return `s`.

## Key Concept 1: Dividing a String into Groups of Size K

```cpp
for (int i = 0; i < s.size(); i += k)
```

Instead of processing every character individually in the outer loop, we move forward by `k` positions.

For example:

```text
s = "11111222223"
k = 3
```

The groups are:

| Group | Starting Index | Characters |
|---|---:|---|
| 1 | 0 | 111 |
| 2 | 3 | 112 |
| 3 | 6 | 222 |
| 4 | 9 | 23 |

The final group can contain fewer than `k` characters.

## Key Concept 2: Converting a Digit Character into an Integer

```cpp
current_sum += (s[j] - '0');
```

Characters representing digits are stored using their character codes.

Subtracting `'0'` converts a digit character into its corresponding integer.

For example:

| Character | Expression | Integer |
|---|---|---:|
| `'1'` | `'1' - '0'` | 1 |
| `'5'` | `'5' - '0'` | 5 |
| `'9'` | `'9' - '0'` | 9 |

This allows us to calculate the actual numerical sum instead of adding character codes.

## Key Concept 3: Converting an Integer into a String

```cpp
answer.push_back(to_string(current_sum));
```

The `to_string()` function converts an integer into its string representation.

For example:

```cpp
int current_sum = 15;
string result = to_string(current_sum);
```

Now `result` contains:

```text
"15"
```

This is important because the problem requires us to concatenate the sums into a new string.

A digit sum can be greater than `9`, so we cannot assume every group produces a single character.

## Key Concept 4: Repeated Transformation Using a While Loop

```cpp
while (s.size() > k)
```

The operation must be repeated until the resulting string contains at most `k` characters.

For example:

```text
Initial:  11111222223
After 1:  345
```

Since the resulting string has length `3`, and `k = 3`, we stop.

The `while` loop handles this repeated transformation automatically.

## C++ Solution

```cpp
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            vector<string> answer;

            for (int i = 0; i < s.size(); i += k) {
                int current_sum = 0;

                for (int j = i; j < s.size() && j < i + k; j++) {
                    current_sum += (s[j] - '0');
                }

                answer.push_back(to_string(current_sum));
            }

            s = "";

            for (const string& chunk : answer) {
                s += chunk;
            }
        }

        return s;
    }
};
```

## Example

**Input:**

```text
s = "11111222223"
k = 3
```

**Output:**

```text
"345"
```

**Explanation:**

We repeatedly divide the string into groups of three characters and calculate their digit sums.

**First Transformation:**

Divide the original string into groups:

| Group | Calculation | Digit Sum |
|---|---|---:|
| 111 | 1 + 1 + 1 | 3 |
| 112 | 1 + 1 + 2 | 4 |
| 222 | 2 + 2 + 2 | 6 |
| 23 | 2 + 3 | 5 |

Concatenate the results:

```text
s = "3465"
```

**Second Transformation:**

The new string has four characters, which is greater than `k = 3`.

Divide it again:

| Group | Calculation | Digit Sum |
|---|---|---:|
| 346 | 3 + 4 + 6 | 13 |
| 5 | 5 | 5 |

Concatenate the results:

```text
s = "135"
```

Now the length of the string is `3`, which is equal to `k`.

Therefore, the loop terminates and returns:

```text
"135"
```

## Complexity Analysis

Let `n` be the initial length of the string and `k` be the group size.

- **Time Complexity:** `O(n log_k n)` — In each transformation, the number of groups is approximately reduced by a factor of `k`. Processing all characters in one transformation takes linear time in the current string length. The process repeats logarithmically many times for `k > 1`.

- **Space Complexity:** `O(n)` — The `answer` vector stores the digit sums of all groups, and the reconstructed string also requires additional space proportional to the current string length.

## Key Takeaways

- `while` loops are useful when an operation must be repeated until a condition becomes false.
- Using `i += k` allows us to process strings in consecutive groups of size `k`.
- `j < s.size() && j < i + k` ensures that we never process characters outside the current group or outside the string.
- Subtracting `'0'` converts a numeric character into an integer.
- `to_string()` converts an integer into its string representation.
- `push_back()` can append an element to a vector.
- Range-based `for` loops can iterate through a vector of strings.
- A string can be reconstructed by concatenating the elements of a vector.

## Conclusion

This solution uses nested loops to calculate the digit sum of each group and a `while` loop to repeat the transformation until the required string length is reached.

The important idea is to separate the problem into three operations: grouping characters, calculating digit sums, and reconstructing the string.

It demonstrates practical usage of string traversal, vectors, nested loops, character-to-integer conversion, and repeated transformations in C++.