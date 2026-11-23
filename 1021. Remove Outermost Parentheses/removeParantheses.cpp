class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer="";
        int depth=0;

        for(char c:s){
            if(c=='('){
                depth++;
                if(depth>1) answer+=c;
             } else
                {
                    if(depth>1) answer+=c;
                    depth--;
                }
            }

        return answer;
     }
};