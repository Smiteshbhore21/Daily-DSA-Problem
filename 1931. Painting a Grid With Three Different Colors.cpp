class Solution {
public:
    vector<string> colStates;
    vector<vector<int>> t;
    int M = 1e9 + 7;
    void generateState(string cur, int m, int len, char prevColor) {
        if (m == len) {
            colStates.push_back(cur);
            return;
        }
        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevColor)
                continue;
            generateState(cur + ch, m, len + 1, ch);
        }
    }

    int solve(int remainCols, int prevIdx, int m) {
        if (remainCols == 0) {
            return 1;
        }
        if (t[remainCols][prevIdx] != -1) {
            return t[remainCols][prevIdx];
        }
        int ways = 0;
        string prevState = colStates[prevIdx];
        for (int i = 0; i < colStates.size(); i++) {
            if (i == prevIdx)
                continue;
            string currState = colStates[i];
            bool valid = 1;
            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                ways = (ways + solve(remainCols - 1, i, m)) % M;
            }
        }
        return t[remainCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateState("", m, 0, '#');

        int totalStates = colStates.size();
        t = vector<vector<int>>(n + 1, vector<int>(totalStates + 1, -1));

        int result = 0;

        for (int i = 0; i < totalStates; i++) {
            result = (result + solve(n - 1, i, m)) % M;
        }
        return result;
    }
};
