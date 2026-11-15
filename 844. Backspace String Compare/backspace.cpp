class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string u="";
        string v="";

        for(char c:s){
            if(c=='#'){
                if(!u.empty()){
                    u.pop_back();
                }
            }

            else{
                u+=c;
            }
        }

        for(char s:t){
            if(s=='#'){
                 if(!v.empty()){
                 v.pop_back();
                }
            }
            

            else{
                v+=s;
            }
        }

        if(u==v){
            return true;
        }

        return false;
    }
};