class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ops = 0;
        int oneCnt = 0;
        for (int i = 0; i < n - 1;) {
            if (s[i] == '1' && s[i + 1] == '0') {
                oneCnt++;
                ops += oneCnt;
                i++;
                while (i < n - 1 && s[i] != '1') {
                    i++;
                }
            } else if (s[i] == '1') {
                oneCnt++;
                i++;
            } else {
                i++;
            }
        }
        return ops;
    }
};
