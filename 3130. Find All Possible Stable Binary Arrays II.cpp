int M = 1e9 + 7;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        // t[onesLeft][zerosLeft][lastWasOne];
        vector<vector<array<int,2>>> t(zero + 1, vector<array<int,2>>(one + 1, {0,0}));

        for (int len = 0; len <= min(zero, limit); len++) {
            t[len][0][0] = 1;
        }

        for (int len = 0; len <= min(one, limit); len++) {
            t[0][len][1] = 1;
        }

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i == 0 || j == 0)
                    continue;

                t[i][j][1] = (t[i][j - 1][0] + t[i][j - 1][1]) % M;
                if (j - 1 >= limit)
                    t[i][j][1] = (t[i][j][1] - t[i][j - 1 - limit][0] + M) % M;

                t[i][j][0] = (t[i - 1][j][0] + t[i - 1][j][1]) % M;
                if (i - 1 >= limit)
                    t[i][j][0] = (t[i][j][0] - t[i - 1 - limit][j][1] + M) % M;
            }
        }
        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};
