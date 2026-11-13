class Solution {
public:
        bool isVowel(char ch) {
            ch = tolower(static_cast<unsigned char>(ch));
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }

    bool halvesAreAlike(string s) {

        int count=0;

        for(int i=0; i<s.size()/2; i++){
            if(isVowel(s[i])){
                count++;
            }
        }

        for(int j=s.size()/2; j<s.size(); j++){
            if(isVowel(s[j])){
                count--;
            }
        }

        if(count==0){
            return true;
        }

        return false;
    }
};
