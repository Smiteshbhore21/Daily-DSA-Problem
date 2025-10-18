class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int distinct = 0;
        int n = nums.size();
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            int newNum = nums[i] - k;
            if (prev < newNum) {
                prev = newNum;
                distinct++;
            } else if (prev < nums[i] + k) {
                prev++;
                distinct++;
            }
        }
        return distinct;
    }
};
