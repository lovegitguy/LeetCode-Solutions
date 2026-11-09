# 121. Best Time to Buy and Sell Stock

**Difficulty:** Easy  
**Topic:** Array, Greedy  
**Language:** C++

## Problem
Given an array `prices`, where `prices[i]` represents the stock price on the ith day, find the maximum profit achievable by buying on one day and selling on a later day.

If no profit is possible, return `0`.

## Approach: Minimum Price Tracking

Instead of checking every possible buy-and-sell pair, traverse the array once while maintaining:

- `minPrice`: The minimum stock price encountered so far.
- `maxProfit`: The maximum profit found so far.

For every price:
1. Calculate the potential profit by subtracting `minPrice` from the current price.
2. Update `maxProfit` if the calculated profit is greater.
3. Update `minPrice` if the current price is smaller.

This ensures that we always buy before selling.

## C++ Solution

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            int profit = prices[i] - minPrice;

            maxProfit = max(maxProfit, profit);

            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
```

## Example

**Input:**
```cpp
prices = {7, 1, 5, 3, 6, 4};
```

| Day | Price | Minimum Price | Maximum Profit |
|---|---:|---:|---:|
| 1 | 7 | 7 | 0 |
| 2 | 1 | 1 | 0 |
| 3 | 5 | 1 | 4 |
| 4 | 3 | 1 | 4 |
| 5 | 6 | 1 | 5 |
| 6 | 4 | 1 | 5 |

**Output:** `5`

Buy at price `1` and sell at price `6`.

## Complexity Analysis

- **Time Complexity:** O(n) — Only one traversal of the array.
- **Space Complexity:** O(1) — Only two additional variables are maintained.

## Key Learning

This problem demonstrates the minimum-tracking technique.

Instead of comparing every pair of elements, maintain the smallest value encountered so far and use it to calculate the best possible result at each position.

This technique is useful in many array optimization problems.