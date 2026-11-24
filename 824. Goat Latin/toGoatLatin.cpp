class Solution {
public:
    string toGoatLatin(string sentence) {
        string word;
        stringstream ss(sentence);
        string result="";
        int count=1;
        while(ss>>word){
                char first=word[0];

                if(first == 'a' || first == 'e' || first == 'i' ||
                first == 'o' || first == 'u' ||
                first == 'A' || first == 'E' || first == 'I' ||
                first == 'O' || first == 'U'){
                    
                }

                else{
                    word=word.substr(1)+word[0];
                }

                word+="ma";
                for(int i=0; i<count; i++){
                    word+='a';
                }
                 if (!result.empty()) {
                result += " ";
            }
                result+=word;
                count++;
        }
        return result;
    }
};