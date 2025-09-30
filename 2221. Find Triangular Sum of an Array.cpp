class Solution {
public:
    int triangularSum(vector<int>& nums) { 
        return solve(nums);
    }

    int solve(vector<int> nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> temp;
        for (int i = 1; i < nums.size(); i++) {
            temp.push_back((nums[i - 1] + nums[i]) % 10);
        }
        return solve(temp);
    }
};
