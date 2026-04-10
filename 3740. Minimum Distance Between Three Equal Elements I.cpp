class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() >= 3) {
                int k = mp[nums[i]].back();
                int j = mp[nums[i]][mp[nums[i]].size() - 3];

                result = min(result, 2 * (k - j));
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
