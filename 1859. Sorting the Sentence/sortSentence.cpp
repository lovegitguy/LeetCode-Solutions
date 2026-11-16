class Solution {
public:
    string sortSentence(string s) {
        vector<string> word(10);
        string currentWord="";
        int wordCount=0;
        for(char c:s){
            if(isdigit(c)){
                word[c-'0'] =currentWord;
                currentWord="";
                wordCount++;
            }
            else if(c!=' '){
                currentWord+=c;
            }
        }

        string answer="";
        for(int i=1;  i<=wordCount; i++){
            answer+=word[i];
            if(i<wordCount){
                answer+=" ";
            }
        }

        return answer;
    }
};