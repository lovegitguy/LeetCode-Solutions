class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int productMinimum=0;
        int productMaximum =0;
        int productdifference=0;
        sort(nums.begin(),nums.end());

        productMaximum = nums[nums.size()-1] * nums[nums.size()-2];

        productMinimum = nums[0] * nums[1];

        productdifference =(productMaximum-productMinimum);
        return productdifference;
    }
};