class Solution {
public:
    string robotWithString(string s) {
        string t = "", paper = "";
        int n = s.size();
        vector<char> rightMin(n);
        rightMin[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(s[i], rightMin[i + 1]);
        }
        int i = 0;
        while (i < n) {
            t.push_back(s[i]);
            char minChar = (i + 1 < n) ? rightMin[i + 1] : s[i];
            while (!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }
            i++;
        }
        while (!t.empty()) {
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};
