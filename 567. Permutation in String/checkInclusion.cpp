class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26]={};
        int freq2[26]={};

        int n=s1.size();
        int m=s2.size();

        if(m<n) return false;

        for(int i=0; i<n; i++){
            freq1[s1[i]-'a']++;
        }

         for(int i=0; i<n; i++){
            freq2[s2[i]-'a']++;
        }

        for(int i=0 ;i<26; i++){
            if(freq1[i]!=freq2[i]){
                break;
            }

            if(i==25) return true;
        }

    for(int i=n; i<m; i++){
        freq2[s2[i-n]-'a']--;
        freq2[s2[i]-'a']++;

        bool match=true;

        for(int j=0; j<26; j++){
            if(freq1[j]!= freq2[j]){
                match=false;
                break;
            }
        }

        if(match) return true;
    }
    return false;
    }
};