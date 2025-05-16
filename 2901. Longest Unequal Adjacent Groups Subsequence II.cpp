class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        int longestSub = 1;
        int longestSubIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hamming(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if (longestSub < dp[i]) {
                            longestSub = dp[i];
                            longestSubIdx = i;
                        }
                    }
                }
            }
        }
        vector<string> res;
        while (longestSubIdx != -1) {
            res.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(begin(res), end(res));
        return res;
    }

    bool hamming(string& a, string& b) {
        int ham = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                ham++;
            }
            if (ham > 1)
                return false;
        }
        return ham == 1;
    }
};
