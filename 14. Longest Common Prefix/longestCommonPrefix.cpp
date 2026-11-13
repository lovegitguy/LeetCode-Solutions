class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        int boundary= strs[0].size();

        for(int i=1; i<strs.size()-1; i++){
           boundary = min(boundary, (int)strs[i].size());
        }

        for(int i=0; i<boundary; i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[0][i]!=strs[j][i]){
                    return commonPrefix;
                }
            }

            commonPrefix+=strs[0][i];
        }

        return commonPrefix;
    }
};