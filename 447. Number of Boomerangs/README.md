# LeetCode 447: Number of Boomerangs

## Problem

You are given `n` points in a 2D plane. A boomerang is a tuple of points `(i, j, k)` such that:

- The distance between point `i` and point `j` is equal to the distance between point `i` and point `k`.
- The order of the points matters.

Return the total number of boomerangs.

## Approach

We use a **Hash Map** to count how many points are at the same distance from a particular center point.

1. Iterate through every point and consider it as the center.
2. Create an `unordered_map` to store the frequency of squared distances.
3. Calculate the squared Euclidean distance between the center and every other point.
4. Before increasing the frequency, add the existing frequency to `totalBoomerangs`.
5. After processing all points, multiply the result by 2 because each pair of points can form two ordered arrangements.

We use squared distance instead of actual distance to avoid unnecessary square root calculations.

### Key Concept: Counting Pairs Using Frequency Maps

Suppose three points have the same distance from a center.

The number of unordered pairs is:

\[
\binom{3}{2} = 3
\]

Since order matters, each pair produces two boomerangs:

\[
3 \times 2 = 6
\]

Our implementation counts each unordered pair once and doubles the final result.

## C++ Solution

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int totalBoomerangs = 0;

        for (auto& centerPoint : points) {
            unordered_map<int, int> distances;

            for (auto& targetPoint : points) {
                int squaredDistance =
                    (centerPoint[0] - targetPoint[0]) *
                    (centerPoint[0] - targetPoint[0]) +
                    (centerPoint[1] - targetPoint[1]) *
                    (centerPoint[1] - targetPoint[1]);

                totalBoomerangs += distances[squaredDistance];
                distances[squaredDistance]++;
            }
        }

        return totalBoomerangs << 1;
    }
};
```

## Example

**Input:**

```text
points = [[0,0],[1,0],[2,0]]
```

**Output:**

```text
2
```

**Explanation:**

Consider `[1,0]` as the center.

- Distance to `[0,0]` = 1
- Distance to `[2,0]` = 1

Both points have the same distance from the center.

Therefore, two ordered boomerangs are possible:

```text
[1,0] -> [0,0] -> [2,0]
[1,0] -> [2,0] -> [0,0]
```

## Complexity Analysis

Let `n` be the number of points.

**Time Complexity:**

\[
O(n^2)
\]

We iterate through every point as a center and calculate distances to all other points.

**Space Complexity:**

\[
O(n)
\]

The hash map stores frequencies of distinct squared distances for one center at a time.

## Key Takeaways

- Use squared Euclidean distance to avoid square roots.
- Use an `unordered_map` to count frequency efficiently.
- Count previously encountered matching distances before incrementing frequency.
- Remember that ordering matters, so multiply the number of unordered pairs by 2.
