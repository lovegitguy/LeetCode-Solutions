class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string c="";
        string d="";

        for(int i=0; i<word1.size(); i++){
            c+=word1[i];
        }

        for(int j=0; j<word2.size(); j++){
            d+=word2[j];
        }

        if(c==d){
            return true;
        }

        return false;
    }
};
