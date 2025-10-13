class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        res.push_back(words[0]);
        string prevS = words[0];
        sort(begin(prevS), end(prevS));
        for (int i = 1; i < n; i++) {
            string currS = words[i];
            sort(begin(currS), end(currS));
            if (currS == prevS) {
                continue;
            } else {
                prevS = currS;
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
