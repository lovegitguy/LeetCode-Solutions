class Solution {
public:
    string defangIPaddr(string address) {
        string answer="";

        for(int i=0;i<address.size();i++){
            if(int(address[i])==46){
                answer.append("[.]");
            }

            else{
                answer+=address[i];
            }
        }
        return answer;
    }
};