class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        long long oddCount= 0;
        int prefixSum= 0;

        int evenCount= 1;
        int oddPrefix= 0;

        for(int num:arr){
            prefixSum+=num;

            if(prefixSum%2==0){
                oddCount= (oddCount+oddPrefix)%MOD;
                evenCount++;
            }

            else{
                oddCount= (oddCount+evenCount)%MOD;
                oddPrefix++;
            }
        }

        return oddCount;
    }
};