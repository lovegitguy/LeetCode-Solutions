class Solution {
public:
    int titleToNumber(string columnTitle) {
       long long correspondingNumber=0;
       
       for(char c:columnTitle){
        int val=c-'A'+1;
        correspondingNumber=correspondingNumber*26+val;
       }

       return static_cast<int> (correspondingNumber);
    }
};