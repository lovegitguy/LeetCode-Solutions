class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();

        if(n>h) return -1;

        for(int j =0; j<=h-n; j++){
            int i=0;

            while(i<n && haystack[j+i]== needle[i]){
                i++;
            }

            if(i==n){
                return j;
            }
        }

        return -1;
    }
};