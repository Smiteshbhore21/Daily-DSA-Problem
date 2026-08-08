class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandSideMatchLen(n, 0);

        int rightMatched = 0;
        int i = n - 1;
        int j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched++, j--;
            }

            rightHandSideMatchLen[i] = rightMatched;
            i--;
        }

        bool canChange = true;
        vector<int> result;

        i = 0, j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } else if (canChange && (i + 1) < n &&
                       rightHandSideMatchLen[i + 1] >= m - j - 1) {
                result.push_back(i);
                j++;
                canChange = false;
            }
            i++;
        }

        return j == m ? result : vector<int>();
    }
};
