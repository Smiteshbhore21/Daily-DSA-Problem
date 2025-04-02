class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, maxDiff = 0, maxi = 0;

        for (int k = 0; k < n; k++) {
            res = max(res, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }
        return res;
    }

    // long long maximumTripletValue(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> leftMaxi(n), rightMaxk(n);

    //     for (int j = 1; j < n; j++) {
    //         leftMaxi[j] = max(leftMaxi[j - 1], nums[j - 1]);
    //     }

    //     for (int j = n - 2; j >= 0; j--) {
    //         rightMaxk[j] = max(rightMaxk[j + 1], nums[j + 1]);
    //     }
    //     long long res = 0;
    //     for (int j = 1; j < n; j++) {
    //         res = max(res, (long long)(leftMaxi[j] - nums[j]) *
    //         rightMaxk[j]);
    //     }
    //     return res;
    // }
};
