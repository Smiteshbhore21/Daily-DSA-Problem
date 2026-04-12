pair<int, int> pos[26];

class Solution {
public:
    Solution() {
        char ch = 'A';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                if (ch >= 'A' && ch <= 'Z') {
                    pos[ch - 'A'] = {i, j};
                    ch++;
                }
            }
            cout << endl;
        }
    }

    int n;
    string word;
    int memo[301][27][27];
    int minimumDistance(string word) {
        this->n = word.size();
        this->word = word;
        for (int i = 0; i < 301; i++) {
            for (int j = 0; j < 27; j++) {
                for (int k = 0; k < 27; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }
        return solve(0, -1, -1);
    }

    int solve(int i, int f1, int f2) {
        if (i == word.size())
            return 0;

        if (memo[i][f1 + 1][f2 + 1] != -1)
            return memo[i][f1 + 1][f2 + 1];

        int curr = word[i] - 'A';

        int cost1 = 0;
        if (f1 != -1) {
            auto a = pos[curr];
            auto b = pos[f1];
            cost1 = abs(a.first - b.first) + abs(a.second - b.second);
        }
        int useF1 = cost1 + solve(i + 1, curr, f2);

        int cost2 = 0;
        if (f2 != -1) {
            auto a = pos[curr];
            auto b = pos[f2];
            cost2 = abs(a.first - b.first) + abs(a.second - b.second);
        }
        int useF2 = cost2 + solve(i + 1, f1, curr);

        return memo[i][f1 + 1][f2 + 1] = min(useF2, useF1);
    }
};
