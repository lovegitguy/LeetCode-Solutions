class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.size()>s.size()){
            return {};
        }

        vector<int> pFreq(26,0);
        vector<int> windowFreq(26,0);

        for(char c:p){
            pFreq[c-'a']++;
        }

         for(int i=0; i<p.size(); i++){
            windowFreq[s[i]-'a']++;
        }

        vector<int> ans;
        
        if(pFreq==windowFreq){
            ans.push_back(0);
        }

       for (int i = 1; i <= s.size() - p.size(); i++) {
         windowFreq[s[i - 1] - 'a']--;
         windowFreq[s[i + p.size() - 1] - 'a']++;

         if(pFreq==windowFreq){
            ans.push_back(i);
         }
         }
         return ans;
    }
};