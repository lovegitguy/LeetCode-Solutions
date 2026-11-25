class Solution {
public:
    bool canFindUnique(const vector<int>& nums, const vector<long long>& p1, const vector<long long>& h1,
                       const vector<long long>& p2, const vector<long long>& h2, int len) {
        const long long MOD1 = 1000000007LL, MOD2 = 1000000009LL;
        int n = nums.size();
        vector<pair<long long, long long>> hashes;
        hashes.reserve(n - len + 1);
        for (int i = 0; i + len <= n; i++) {
            long long sub1 = (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;
            long long sub2 = (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;
            hashes.push_back({sub1, sub2});
        }
        sort(hashes.begin(), hashes.end());
        int total = hashes.size();
        for (int i = 0; i < total; i++) {
            bool samePrev = (i > 0 && hashes[i] == hashes[i - 1]);
            bool sameNext = (i + 1 < total && hashes[i] == hashes[i + 1]);
            if (!samePrev && !sameNext) return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        const long long BASE1 = 1315423911LL, BASE2 = 2654435761LL;
        const long long MOD1 = 1000000007LL, MOD2 = 1000000009LL;
        vector<long long> p1(n + 1, 1), p2(n + 1, 1), h1(n + 1, 0), h2(n + 1, 0);
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