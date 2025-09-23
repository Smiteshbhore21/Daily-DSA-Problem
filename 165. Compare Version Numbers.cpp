class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> revision1, revision2;
        int revision = 0;
        for (const char& ch : version1) {
            if (ch == '.') {
                revision1.push_back(revision);
                revision = 0;
            } else {
                revision = (revision * 10) + (ch - '0');
            }
        }
        revision1.push_back(revision);
        revision = 0;
        for (const char& ch : version2) {
            if (ch == '.') {
                revision2.push_back(revision);
                revision = 0;
            } else {
                revision = (revision * 10) + (ch - '0');
            }
        }
        revision2.push_back(revision);
        int n = revision1.size(), m = revision2.size();
        int i = 0, j = 0;
        int minSize = min(n, m);
        for (i; i < minSize; i++, j++) {
            if (revision1[i] < revision2[i]) {
                return -1;
            } else if (revision1[i] > revision2[i]) {
                return 1;
            }
        }
        while (i < n) {
            if (revision1[i] != 0) {
                return 1;
            }
            i++;
        }
        while (j < m) {
            if (revision2[j] != 0) {
                return -1;
            }
            j++;
        }
        return 0;
    }
};
