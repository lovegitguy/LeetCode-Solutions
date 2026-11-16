class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            vector<string> answer;

            for (int i = 0; i < s.size(); i += k) {
                int current_sum = 0;
                for (int j = i; j < s.size() && j < i + k; j++) {
                    current_sum += (s[j] - '0');
                }
                answer.push_back(to_string(current_sum));
            }

            s = "";
            for (const string& chunk : answer) {
                s += chunk;
            }
        }

        return s;
    }
};