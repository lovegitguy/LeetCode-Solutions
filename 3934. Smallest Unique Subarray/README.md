# Smallest Unique Subarray

## Problem

Given an integer array `nums`, find the minimum length of a subarray that occurs exactly once in the array.

The implementation uses double rolling hash and binary search to identify the smallest length for which at least one unique subarray exists.

## Approach

We use three main techniques:

1. **Double Rolling Hash** – To efficiently represent and compare subarrays.
2. **Sorting** – To identify duplicate subarray hashes.
3. **Binary Search on Answer** – To find the minimum valid subarray length.

### Step 1: Precompute Powers and Prefix Hashes

We maintain two independent polynomial hash systems.

- `p1`, `p2`: Store powers of the two hash bases.
- `h1`, `h2`: Store prefix hashes of the array.

This allows us to calculate the hash of any subarray in O(1) time.

### Step 2: Calculate Subarray Hashes

Inside `canFindUnique()`, we calculate the hash of every subarray of the given length.

The formula is:

```cpp
subHash = (prefixHash[i + len]
          - prefixHash[i] * power[len]
          + MOD) % MOD;
```

We calculate two hashes for every subarray and store them as a pair.

### Step 3: Sort the Hashes

We sort all hash pairs.

If two subarrays have identical hash pairs, they are treated as duplicates.

After sorting, duplicate hashes appear next to each other.

A hash is unique if it differs from both its previous and next neighbors.

### Step 4: Binary Search on Answer

We binary search over possible subarray lengths:

```cpp
int lo = 1, hi = n, ans = n;
```

For every middle length:

- If at least one unique subarray exists, save the answer and search for a smaller length.
- Otherwise, search for a larger length.

The search relies on the monotonic property: if a unique subarray exists at length L, a longer subarray containing it can also be unique.

## C++ Solution

```cpp
class Solution {
public:
    bool canFindUnique(
        const vector<int>& nums,
        const vector<long long>& p1,
        const vector<long long>& h1,
        const vector<long long>& p2,
        const vector<long long>& h2,
        int len
    ) {
        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;

        int n = nums.size();

        vector<pair<long long, long long>> hashes;
        hashes.reserve(n - len + 1);

        for (int i = 0; i + len <= n; i++) {
            long long sub1 =
                (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;

            long long sub2 =
                (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;

            hashes.push_back({sub1, sub2});
        }

        sort(hashes.begin(), hashes.end());

        int total = hashes.size();

        for (int i = 0; i < total; i++) {
            bool samePrev = (i > 0 && hashes[i] == hashes[i - 1]);
            bool sameNext = (i + 1 < total && hashes[i] == hashes[i + 1]);

            if (!samePrev && !sameNext)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        const long long BASE1 = 1315423911LL;
        const long long BASE2 = 2654435761LL;

        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; i++) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;

            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }

        int lo = 1, hi = n, ans = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canFindUnique(nums, p1, h1, p2, h2, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
```

## Key Concepts

### 1. Rolling Hash

Rolling hash converts a sequence into a numerical representation.

It allows efficient comparison of subarrays without comparing every element individually.

### 2. Prefix Hashing

Prefix hashes allow us to calculate subarray hashes in constant time.

Instead of recalculating the hash of every subarray from scratch, we reuse previously calculated values.

### 3. Double Hashing

We use two different bases and two different moduli.

This reduces the probability of hash collisions compared with using a single hash.

### 4. Binary Search on Answer

Instead of checking every possible subarray length individually, we use binary search.

This is possible because the existence of a unique subarray is monotonic with respect to increasing length.

### 5. Sorting and Adjacent Duplicate Detection

After sorting hash pairs, equal hashes become adjacent.

We can identify a unique hash by checking its previous and next elements.

## Complexity Analysis

Let `n` be the length of the input array.

**Time Complexity: O(n log² n)**

- Prefix hash preprocessing: O(n).
- Hash calculation for one length: O(n).
- Sorting hashes for one length: O(n log n).
- Binary search over lengths: O(log n).

Total:

O(n log² n)

**Space Complexity: O(n)**

We store:
- Two power arrays.
- Two prefix hash arrays.
- A temporary vector of hash pairs.

## Important Learning Notes

This implementation combines several advanced concepts:

- Polynomial rolling hash.
- Prefix hashing.
- Modular arithmetic.
- Double hashing.
- Sorting hash pairs.
- Binary search on answer.
- Monotonic predicates.

