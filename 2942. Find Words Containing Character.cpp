class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (any_of(words[i].begin(), words[i].end(),
                       [&x](char ch) { return x == ch; })) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
