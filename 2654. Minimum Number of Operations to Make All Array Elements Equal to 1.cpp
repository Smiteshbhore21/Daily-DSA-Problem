class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int gcd = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            gcd = __gcd(gcd, nums[i]);
            if (nums[i] != 1)
                cnt++;
        }

        if (gcd != 1) {
            return -1;
        }

        int minI = INT_MAX;
        for (int i = 0; i < n; i++) {
            int gcd = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1) {
                    minI = min(minI, j - i + 1);
                }
            }
        }
        return (cnt - 1) + (minI - 1);
    }
};
