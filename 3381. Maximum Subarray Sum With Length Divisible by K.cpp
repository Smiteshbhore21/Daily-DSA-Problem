class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        long long pref = 0;

        vector<long long> minPref(k, LLONG_MAX);

        minPref[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int rem = i % k;
            if (i >= k - 1) {
                ans = max(ans, pref - minPref[rem]);
            }
            if (i == k - 1) {
                ans = pref;
            }
            minPref[rem] = min(minPref[rem], pref);
        }
        return ans;
    }
};

// TLE -> O(n)
// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<long long> prefixSum(n, 0);
//         prefixSum[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             prefixSum[i] = prefixSum[i - 1] + nums[i];
//         }
//         long long ans = LLONG_MIN;
//         for (int len = k; len <= n; len += k) {
//             for (int s = 0; s + len - 1 < n; s++) {
//                 int e = s + len - 1;
//                 long long sum = prefixSum[e] - (s > 0 ? prefixSum[s - 1] :
//                 0LL); ans = max(ans, sum);
//             }
//         }
//         return ans;
//     }
// };
