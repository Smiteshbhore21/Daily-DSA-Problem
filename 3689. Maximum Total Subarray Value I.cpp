class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long minEle = INT_MAX, maxEle = INT_MIN;
        for (int i = 0; i < n; i++) {
            minEle = min(minEle, (long long)nums[i]);
            maxEle = max(maxEle, (long long)nums[i]);
        }
        return (maxEle - minEle) * k;
    }
};
