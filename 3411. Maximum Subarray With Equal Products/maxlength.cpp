class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0, ans = 0;

        for (int right = 0; right < n; ++right) {
            long long prod = 1, l = 1;
            int g = 0;

            for (int i = left; i <= right; ++i) {
                prod *= nums[i];
                g = (g == 0) ? nums[i] : gcd(g, nums[i]);
                l = lcm(l, static_cast<long long>(nums[i]));
            }

            while (left <= right && prod > 1LL * l * g) {
                ++left;
                prod = 1;
                l = 1;
                g = 0;
                for (int i = left; i <= right; ++i) {
                    prod *= nums[i];
                    g = (g == 0) ? nums[i] : gcd(g, nums[i]);
                    l = lcm(l, static_cast<long long>(nums[i]));
                }
            }

            if (left <= right && prod == 1LL * l * g) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};