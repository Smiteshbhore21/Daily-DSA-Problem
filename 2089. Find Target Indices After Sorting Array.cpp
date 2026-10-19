class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<int> ans;
        vector<int> countSort(101, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                countSort[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int val = countSort[i];
            if (val)
                ans.push_back(i);
        }

        return ans;
    }
};
