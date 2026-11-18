class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> answer;

        for(char c:s){
            answer.push_back(c);
        }

        for(char w:t){
            auto it= find(answer.begin(), answer.end(), w);
            if(it==answer.end()){
                return w;
            }
            else{
                answer.erase(it);
            }
        }

        return ' ';
    }
};