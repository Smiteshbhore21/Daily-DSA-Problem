class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> charPos(26);
        for (int i = 0; s[i]; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (charPos[j].size() > 0) {
                        s[charPos[j].back()] = '*';
                        charPos[j].pop_back();
                        break;
                    }
                }
            } else {
                charPos[s[i] - 'a'].push_back(i);
            }
        }
        string ans;
        for (const char& ch : s) {
            if (ch != '*')
                ans += ch;
        }
        return ans;
    }
};
