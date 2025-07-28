class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsetCount = pow(2, n) - 1;
        int maxBitOR = 0;
        for (int i = 0; i < n; i++) {
            maxBitOR |= nums[i];
        }
        int count = 0;
        dfs(0, 0, count, maxBitOR, nums);
        return count;
    }

    void dfs(int idx, int currOR, int& count, int& target, vector<int>& nums) {
        if (idx == nums.size()) {
            if (currOR == target)
                count++;
            return;
        }
        dfs(idx + 1, currOR | nums[idx], count, target, nums);
        dfs(idx + 1, currOR, count, target, nums);
    }
};
