class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int& num : nums) {
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }
            bool found = false;
            for (int bit = 0; bit < 32; bit++) {
                if ((num & (1 << bit)) == 0) {
                    int prev = bit - 1;
                    int x = num ^ (1 << prev);
                    ans.push_back(x);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
