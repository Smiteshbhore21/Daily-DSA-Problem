class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> leftClosestR(n, -1), rightClosestL(n, -1);
        if (dominoes[0] == 'R')
            leftClosestR[0] = 0;

        for (int i = 1; i < n; i++) {
            if (dominoes[i] == 'R') {
                leftClosestR[i] = i;
            } else if (dominoes[i] == '.') {
                leftClosestR[i] = leftClosestR[i - 1];
            } else {
                continue;
            }
        }

        if (dominoes[n - 1] == 'L')
            rightClosestL[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                rightClosestL[i] = i;
            } else if (dominoes[i] == '.') {
                rightClosestL[i] = rightClosestL[i + 1];
            } else {
                continue;
            }
        }

        for (int i = 0; i < n; i++) {
            int distLeftR = abs(i - leftClosestR[i]),
                distRightL = abs(i - rightClosestL[i]);
            if (rightClosestL[i] == leftClosestR[i]) {
                dominoes[i] = '.';
            } else if (rightClosestL[i] == -1) {
                dominoes[i] = 'R';
            } else if (leftClosestR[i] == -1) {
                dominoes[i] = 'L';
            } else if (distRightL == distLeftR) {
                dominoes[i] = '.';
            } else {
                dominoes[i] = distLeftR < distRightL ? 'R' : 'L';
            }
        }
        return dominoes;
    }
};
