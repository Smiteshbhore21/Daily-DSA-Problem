class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        long long rem = 0;
        for (int i = 0; i < n; i++) {
            rem = ((rem << 1) + nums[i]) % 5;
            ans.push_back(rem == 0);
        }
        return ans;
    }
};
