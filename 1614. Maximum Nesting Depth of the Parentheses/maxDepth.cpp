class Solution {
public:
    int maxDepth(string s) {
        int current_depth=0;
        int max_depth=0;

        for(char c : s){
            if(c=='('){
             current_depth+=1;
            max_depth=max(max_depth, current_depth);
            }
          
            else if(c==')'){
                current_depth-=1;
            }
        }

        return max_depth;
    }
};