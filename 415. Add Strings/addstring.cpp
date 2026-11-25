class Solution {
public:
    string addStrings(string num1, string num2) {
        int count=0;
        string result;
        int i=num1.size()-1;
        int j=num2.size()-1;

        while(i>=0 || j>=0 || count>0 ){
            int sum=count;
            if(i>=0){
                sum+=num1[i]-'0';
                i--;
            }

             if(j>=0){
                sum+=num2[j]-'0';
                j--;
            }

            result.push_back((sum%10)+'0');
            count=sum/10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};