class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCnt = 0;
        int flips = 0;
        for (const char& ch : s) {
            if (ch == '1') {
                oneCnt++;
            } else if (oneCnt > 0) {
                flips++;
                oneCnt--;
            }
        }
        return flips;
    }
};
