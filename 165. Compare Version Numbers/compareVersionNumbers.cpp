class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int i = 0;
        int j = 0;

        while (i < m || j < n) {
            string answer1 = "";
            while (i < m && version1[i] != '.') {
                answer1 += version1[i];
                i++;
            }

            string answer2 = "";
            while (j < n && version2[j] != '.') {
                answer2 += version2[j];
                j++;
            }

            int rev1 = answer1.empty() ? 0 : stoi(answer1);
            int rev2 = answer2.empty() ? 0 : stoi(answer2);

            if (rev1 < rev2) return -1;
            if (rev1 > rev2) return 1;

            if (i < m && version1[i] == '.') i++;
            if (j < n && version2[j] == '.') j++;
        }

        return 0;
    }
};