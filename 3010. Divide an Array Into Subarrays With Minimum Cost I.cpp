class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = nums[0];

        int min1 = INT_MAX, min2 = INT_MAX;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (min1 >= nums[i]) {
                min2 = min1;
                min1 = nums[i];
            } else if (min2 >= nums[i]) {
                min2 = nums[i];
            }
        }

        return result + min1 + min2;
    }
};
