class Solution {
public:
    unordered_map<string, vector<char>> validPatterns;
    unordered_map<string, bool> memo;
    int n;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        this->n = n;
        validPatterns.clear();
        for (const string& str : allowed) {
            validPatterns[str.substr(0, 2)].push_back(str[2]);
        }
        return solve(bottom, 0, "");
    }

    bool solve(string curr, int idx, string above) {
        if (curr.length() == 1)
            return true;

        string key = curr + "_" + to_string(idx) + "_" + above;

        if (memo.find(key) != memo.end())
            return memo[key];

        if (curr.length() - 1 == idx)
            return solve(above, 0, "");

        string pair = curr.substr(idx, 2);
        if (validPatterns.find(pair) == validPatterns.end())
            return memo[key] = false;

        for (const char& ch : validPatterns[pair]) {
            above.push_back(ch);

            if (solve(curr, idx + 1, above))
                return memo[key] = true;

            above.pop_back();
        }

        return memo[key] = false;
    }
};
