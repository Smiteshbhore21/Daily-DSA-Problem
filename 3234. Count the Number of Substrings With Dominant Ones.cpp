class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCntOne(n, 0);
        cumCntOne[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            cumCntOne[i] = cumCntOne[i - 1] + ((s[i] == '1') ? 1 : 0);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int oneCount =
                    cumCntOne[j] - (i - 1 >= 0 ? cumCntOne[i - 1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if ((zeroCount * zeroCount) > oneCount) {
                    int uselessIndices = (zeroCount * zeroCount) - oneCount;
                    j += (uselessIndices - 1);
                } else if ((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else {
                    result += 1;

                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if (next >= n) {
                        result += (n - j - 1);
                        break;
                    } else {
                        result += k;
                    }
                    j = next;
                }
            }
        }
        return result;
    }
};
