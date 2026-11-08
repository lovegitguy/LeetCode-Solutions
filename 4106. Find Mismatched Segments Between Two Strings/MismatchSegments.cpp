class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        vector<vector<string>> answer;

        int start = -1;

        for(int i=0;i<s1.length();i++) {

            if(s1[i]!=s2[i]) {

                if(start==-1) {
                    start=i;
                }

            }
            else{

                if(start != -1) {
                    int len= i-start;
                    string sub1 = s1.substr(start, len);
                    string sub2 = s2.substr(start, len);
                    answer.push_back({sub1, sub2});
                    start =-1;
                }
            }
        }

        if(start != -1) {

            int len = s1.length() - start;
            string sub1 = s1.substr(start, len);
            string sub2 = s2.substr(start, len);
            answer.push_back({sub1, sub2});
        }

        return answer;
    }
};