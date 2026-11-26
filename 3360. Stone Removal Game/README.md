# LeetCode 3360: Stone Removal Game

## Problem
Alice and Bob take turns removing stones from a pile. Alice removes 10 stones on her first turn, and the number of stones required decreases by 1 after each turn. A player who cannot remove the required number loses.

Determine whether Alice wins.

## Approach
- Initialize `removal = 10` and `count = 0`.
- While enough stones remain, remove the required number.
- Decrease `removal` after every successful turn.
- Increment `count` to track successful removals.
- If `count` is odd, Alice wins; otherwise, Bob wins.

## C++ Solution
```cpp
class Solution {
public:
    bool canAliceWin(int n) {
        int removal = 10;
        int count = 0;

        while (n >= removal) {
            n -= removal;
            removal--;
            count++;
        }

        return count % 2 != 0;
    }
};
```

## Complexity Analysis
- **Time Complexity:** O(1) — at most 10 iterations.
- **Space Complexity:** O(1) — only a constant number of variables are used.