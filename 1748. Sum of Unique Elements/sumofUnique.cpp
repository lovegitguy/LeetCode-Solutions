class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int , int> frequency;
        int sum=0;
        for(int n:nums){
            frequency[n]++;
        }

        for(pair<int, int> f:frequency){
            if(f.second==1){
                sum+=f.first;
            }
        }

        return sum;
    }
};