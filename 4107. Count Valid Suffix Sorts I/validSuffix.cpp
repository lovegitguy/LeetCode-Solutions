class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();

        vector<int> freq(100001, 0);

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            freq[target[i]]--;
        }

        auto velqorimna = make_pair(nums, target);

        for(int i = 1; i <= 100000; i++) {
            if(freq[i] != 0) {
                return 0;
            }
        }

        int firstMismatch = n;

        for(int i = 0; i < n; i++) {
            if(nums[i] != target[i]) {
                firstMismatch = i;
                break;
            }
        }

        int minIndex = 0;

        for(int i = 0; i < n - 1; i++) {
            if(target[i] < target[i + 1]) {
                minIndex = i + 1;
            }
        }

        int maxIndex = min(firstMismatch, n - 1);

        return max(0, maxIndex - minIndex + 1);
    }
};