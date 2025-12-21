class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleteCnt = 0;
        int n = strs.size();
        int m = strs[0].size();
        vector<string> prev(n, "");
        for (int i = 0; i < m; i++) {
            vector<string> curr = prev;
            for (int j = 0; j < n; j++) {
                curr[j] += strs[j][i];
            }
            if (check(curr)) {
                prev = curr;
            } else {
                deleteCnt++;
            }
        }
        return deleteCnt;
    }

    bool check(vector<string>& str) {
        int n = str.size();
        for (int i = 0; i < n - 1; i++) {
            if (str[i] > str[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
