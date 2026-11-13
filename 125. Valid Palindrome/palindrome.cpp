class Solution {
public:
    bool isPalindrome(string s) {
        string answer="";

        for(int i=0;i<s.size(); i++){

            if(isalnum((unsigned char)s[i])){
                answer+=tolower((unsigned char)s[i]);
            }
        }

        string reversedanswer= answer;
        reverse(answer.begin(), answer.end());

        return answer==reversedanswer;
    }
};