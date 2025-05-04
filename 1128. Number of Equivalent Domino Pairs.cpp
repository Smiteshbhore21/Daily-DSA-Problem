class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> vec(100, 0);
        int ans = 0;
        for (auto& x : dominoes) {
            if (x[0] > x[1]) {
                swap(x[0], x[1]);
            }
            ans += vec[(x[0] * 10) + x[1]];
            vec[(x[0] * 10) + x[1]]++;
        }
        return ans;
    }
};
