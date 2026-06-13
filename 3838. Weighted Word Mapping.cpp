class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string str : words) {
            int sum = 0;
            for (char ch : str) {
                sum += weights[ch - 'a'];
            }
            ans += (25 - ((sum % 26) - 'a'));
        }
        return ans;
    }
};
