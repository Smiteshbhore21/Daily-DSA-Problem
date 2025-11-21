class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // char -> {leftMostIdx, rightMostIdx}
        unordered_map<int, pair<int, int>> mp;
        int totalPalindromes = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (mp.find(ch - 'a') != mp.end()) {
                mp[ch - 'a'].second = i;
            } else {
                mp[ch - 'a'] = {i, i};
            }
        }

        for (auto& [key, val] : mp) {
            if (val.first == val.second)
                continue;
            totalPalindromes += unordered_set<char>(s.begin() + val.first + 1,
                                                    s.begin() + val.second)
                                    .size();
        }
        return totalPalindromes;
    }
};
