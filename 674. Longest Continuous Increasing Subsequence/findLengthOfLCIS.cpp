class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currentLen=1;
        int maxlen=1;
        if(nums.empty()){
            return 0;
        }
        for(int i=1; i<static_cast<int>(nums.size()); i++){
            if(nums[i]>nums[i-1]){
                currentLen++;
                maxlen= max(maxlen,currentLen);
            }

            else{
                currentLen=1;
            }
        }

        return maxlen;
    }
};