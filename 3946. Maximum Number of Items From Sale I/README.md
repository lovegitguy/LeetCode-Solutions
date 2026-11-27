# Maximum Sale Items

## Problem

Given a collection of items represented by two values:

- `factor`: The item's factor.
- `price`: The item's price.

You are also given a budget.

The objective is to maximize the number of sale items that can be obtained under the budget.

For an item with factor `x`, its contribution is the number of items whose factors are divisible by `x`.

We use Dynamic Programming to select items within the budget and then use the remaining budget to purchase additional items at the minimum price.

## Approach

We use **0/1 Knapsack Dynamic Programming combined with Greedy Optimization**.

### Step 1: Initialize DP

Create a DP array:

```cpp
vector<int> f(budget + 1, 0);
```

Here:

`f[j]` represents the maximum contribution achievable using a budget of at most `j`.

### Step 2: Find the Minimum Price

```cpp
int mn = INT_MAX;
```

While processing each item, update the minimum price:

```cpp
mn = min(mn, price);
```

This helps us determine how many additional items can be purchased using the remaining budget.

### Step 3: Calculate Each Item's Contribution

For every item, count how many items have factors divisible by its factor.

```cpp
int cnt = 0;

for (const auto& jItem : items) {
    if (jItem[0] % factor == 0) {
        cnt++;
    }
}
```

This gives the contribution associated with selecting the current item.

### Step 4: Apply 0/1 Knapsack

```cpp
for (int j = budget; j >= price; --j) {
    f[j] = max(f[j], f[j - price] + cnt);
}
```

We have two choices:

1. Do not select the current item: `f[j]`
2. Select the current item: `f[j - price] + cnt`

We take the maximum.

**Why iterate backwards?**

Backward iteration ensures that each item is selected at most once.

If we iterated forwards, the same item could potentially be selected multiple times during one iteration.

### Step 5: Use the Remaining Budget

```cpp
for (int i = 0; i <= budget; ++i) {
    ans = max(ans, f[i] + (budget - i) / mn);
}
```

For every possible budget `i` used by the DP:

- `f[i]` gives the maximum contribution.
- `budget - i` is the remaining budget.
- Dividing by `mn` calculates how many additional minimum-price items can be purchased.

We maximize the total.

## Key Concept: 0/1 Knapsack

In 0/1 Knapsack, every item can either be selected or not selected.

The transition is:

\[
dp[j] = \max(dp[j], dp[j-w] + v)
\]

Where:

- `j` = current capacity.
- `w` = item weight or cost.
- `v` = item value or contribution.

In this problem:

- `price` acts as the weight.
- `cnt` acts as the value.
- `budget` acts as the knapsack capacity.

Backward iteration prevents selecting an item multiple times.

## C++ Solution

```cpp
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> f(budget + 1, 0);
        int mn = INT_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];

            mn = min(mn, price);

            int cnt = 0;
            for (const auto& jItem : items) {
                if (jItem[0] % factor == 0) {
                    cnt++;
                }
            }

            for (int j = budget; j >= price; --j) {
                f[j] = max(f[j], f[j - price] + cnt);
            }
        }

        int ans = 0;
        for (int i = 0; i <= budget; ++i) {
            ans = max(ans, f[i] + (budget - i) / mn);
        }

        return ans;
    }
};
```

## Example

A numerical example depends on the original problem's exact rules, particularly whether the remaining budget can be spent on unlimited minimum-price items.

The implementation above assumes that:

- Each item can be selected at most once in the knapsack.
- Selecting an item contributes the number of items whose factors are divisible by its factor.
- Additional minimum-price purchases are allowed using the remaining budget.

## Complexity Analysis

Let:

- `n` = number of items.
- `B` = budget.

**Time Complexity:**

\[
O(n^2 + nB)
\]

Explanation:

- The outer loop processes `n` items.
- For each item, the inner counting loop takes `O(n)`.
- The knapsack transition takes `O(B)` per item.

Therefore:

\[
O(n^2+nB)
\]

**Space Complexity:**

\[
O(B)
\]

The DP array contains `budget + 1` elements.

## Key Takeaways

- 0/1 Knapsack is useful when each item can be selected at most once.
- Backward iteration prevents reusing the same item.
- An item's value does not always have to be 1; it can represent a calculated contribution.
- Combining DP with a greedy observation can simplify the remaining-budget calculation.
