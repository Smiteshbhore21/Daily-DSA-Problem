class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        int fSum = 0;
        for (int i = 0; i < n; i++) {
            fSum += (i * nums[i]);
            sum += nums[i];
        }

        int result = fSum;
        int lastIdx = n - 1;
        for (int i = 0; i < n; i++) {
            int newF = fSum + sum - (n * nums[n - 1 - i]);
            result = max(result, newF);
            fSum = newF;
        }
        return result;
    }
};
