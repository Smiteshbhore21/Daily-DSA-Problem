class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0, n1 = nums1.size(),
                  n2 = nums2.size();
        for (int i = 0; i < n1; i++) {
            sum1 += nums1[i] == 0 ? 1 : nums1[i];
            zero1 += nums1[i] == 0 ? 1 : 0;
        }
        for (int i = 0; i < n2; i++) {
            sum2 += nums2[i] == 0 ? 1 : nums2[i];
            zero2 += nums2[i] == 0 ? 1 : 0;
        }
        if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0))
            return -1;

        return max(sum1, sum2);
    }
};
