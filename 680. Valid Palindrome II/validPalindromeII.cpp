class Solution {
public:
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
    bool ispalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] == s[end]) {
            start++;
            end--;
        } else {
            return ispalindrome(s, start + 1, end) || ispalindrome(s, start, end - 1);
        }
    }
    return true;
}
    }
};