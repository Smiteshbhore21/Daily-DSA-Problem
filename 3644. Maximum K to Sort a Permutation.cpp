class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted_nums = nums;

        sort(begin(sorted_nums), end(sorted_nums));

        int k = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i == nums[i])
                continue;

            k &= nums[i];
        }

        return k == INT_MAX ? 0 : k;
    }
};
