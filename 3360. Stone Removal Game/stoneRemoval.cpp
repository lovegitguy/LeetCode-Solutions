class Solution {
public:
    bool canAliceWin(int n) {
        int removal=10;
        int count=0;

        while(n>=removal){
            n=n-removal;
            removal--;
            count++;
        }

        if(count%2!=0){
            return true;
        }

        return false;
        
    }
};