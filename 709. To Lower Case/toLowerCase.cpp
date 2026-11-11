class Solution {
public:
    string toLowerCase(string s) {
    string output="";
       for(int i=0;i<s.size();i++){
        
        if(int(s[i]) >=65 && int(s[i])<=90){
            output+=tolower(s[i]);
        }

        else{
            output+=s[i];
        }
       }
        return output;
    }
   
};