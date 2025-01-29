class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), nNumSum = (n * (n + 1)) / 2, totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        return nNumSum - totalSum;
    }
};
