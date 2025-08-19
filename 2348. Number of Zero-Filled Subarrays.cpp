class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n;) {
            if (nums[i] == 0) {
                long long count = 1;
                i++;
                while (i < n && nums[i] == 0) {
                    count++;
                    i++;
                }
                ans += (count * (count + 1) / 2);
            } else
                i++;
        }
        return ans;
    }
};
