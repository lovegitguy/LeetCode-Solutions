class Solution {
public:
    string reverseOnlyLetters(string s) {

        int start=0;
        int end=s.size()-1;

        while(start<end){

            if(!isalpha(s[end])){
                end--;
                continue;
            }

            if(!isalpha(s[start])){
                start++;
                continue;
            }

            swap(s[start], s[end]);
            start++;
            end--;
            
        }

        return s;
    }
};