class Solution {
public:
    int countSubstrings(string s) {
        int count=0;

        for(int i=0;i<s.size(); i++){
            
            for(int j=i; j<s.size(); j++){
                string current=s.substr(i, j-i+1);
                string reversed= current;
                reverse(reversed.begin(), reversed.end());
                
                if(current==reversed){
                    count++;
                 }
            }
          
        }
        return count;
    }
};