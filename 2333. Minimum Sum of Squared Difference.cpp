class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();

        vector<int> countDiff(1e5 + 1, 0);

        for (int i = 0; i < n; i++) {
            countDiff[abs(nums1[i] - nums2[i])]++;
        }

        int K = k1 + k2;
        for (int currDiff = 1e5; currDiff > 0 && K > 0; currDiff--) {
            int cntOps = min(countDiff[currDiff], K);

            countDiff[currDiff] -= cntOps;
            countDiff[currDiff - 1] += cntOps;
            K -= cntOps;
        }

        long long result = 0;

        for (long long d = 1; d <= 1e5; d++) {
            result += (countDiff[d] * d * d);
        }

        return result;
    }
};
