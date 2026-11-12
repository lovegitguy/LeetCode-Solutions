class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        
        for(int i=0; i<s.size(); i+=2*k){
            int right=min(i+k,n);
            reverse(s.begin()+i,s.begin()+right);  
        }

        return s;
    }
};

// ANOTHER SOLUTION

class Solution {
public:
    string reverseStr(string s, int k) {
       
        for(int i = 0; i<s.size(); i+=2*k){
             int start=i;
            int end= min(start + k - 1, (int)s.size() - 1);

            while(start<end){
              swap(s[start],s[end]);
              start++;
              end--;
            }
        }

        return s;
    }
};