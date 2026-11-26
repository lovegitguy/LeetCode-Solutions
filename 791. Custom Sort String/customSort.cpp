class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }

        string result;
        result.reserve(s.size());

        for(char c:order){
            int index=c-'a';
            result.append(freq[index],c);
            freq[index]=0;
        }

        for(int i=0; i<26;i++){
            if(freq[i]>0){
                result.append(freq[i],static_cast<char> ('a'+i));
            }
        }

        return result;
    }
};