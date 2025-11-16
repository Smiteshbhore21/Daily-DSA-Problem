int MOD = 1e9 + 7;
class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {
            if (s[j] == '0') {
                int oneCnt = j - i;
                if (oneCnt % 2 == 0) {
                    cnt =
                        (cnt + ((1ll * oneCnt * (oneCnt / 2)) + (oneCnt / 2))) %
                        MOD;
                } else {
                    cnt = (cnt + ((1ll * oneCnt * (oneCnt + 1) / 2))) % MOD;
                }
                j++;
                i = j;
            } else {
                j++;
            }
        }
        int oneCnt = j - i;
        if (oneCnt % 2 == 0) {
            cnt = (cnt + ((1ll * oneCnt * (oneCnt / 2)) + (oneCnt / 2))) % MOD;
        } else {
            cnt = (cnt + ((1ll * oneCnt * (oneCnt + 1) / 2))) % MOD;
        }
        return cnt;
    }
};
