class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();

        for(int i=0;i<size;i++){
            int left=(i==0) ? 0: flowerbed[i-1];

            int right=(i==size-1) ? 0: flowerbed[i+1];

            if(left + flowerbed[i] + right ==0){
                flowerbed[i]=1;
                --n;
            }
        }
        return n <= 0;
    }
};