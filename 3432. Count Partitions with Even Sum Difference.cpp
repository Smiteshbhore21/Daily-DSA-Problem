class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cnt = 0;
        int currSum = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int num = nums[i];
            currSum += num;
            sum -= num;
            if ((currSum - sum) % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
