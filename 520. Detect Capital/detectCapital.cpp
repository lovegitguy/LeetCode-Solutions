class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercount=0;

        for(int i=0; i<word.size(); i++){
            if(isupper(word[i])){
                uppercount++;
            }
        }

        if(uppercount==word.size()){
            return true;
        }

        else if(uppercount==0){
            return true;
        }

        else if(uppercount==1 && isupper(word[0])){
            return true;
        }

        return false;
    }
};