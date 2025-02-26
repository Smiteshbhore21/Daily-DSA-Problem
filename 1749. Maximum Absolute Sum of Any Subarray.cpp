class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // int n = nums.size(), maxSum = INT_MIN;
        // for (int i = 0; i < n; i++) {u
        //     int sum = 0;
        //      for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         maxSum = max(maxSum, abs(sum));
        //     }
        // }
        // return maxSum;
        int n = nums.size(), prefix = 0, minPrefix = 0, maxPrefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }
        return maxPrefix - minPrefix;
    }
};
