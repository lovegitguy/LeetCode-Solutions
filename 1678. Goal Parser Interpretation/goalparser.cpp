class Solution {
public:
    string interpret(string command) {
    string answer;
        for(int i =0;i<command.size();i++){
            if(command[i]=='G'){
                answer+='G';
            }

            else if(command.substr(i,2)=="()"){
                answer+="o";
            }

            else if(command.substr(i,4)=="(al)"){
                answer+="al";
            }
        }
        return answer;
    }
};