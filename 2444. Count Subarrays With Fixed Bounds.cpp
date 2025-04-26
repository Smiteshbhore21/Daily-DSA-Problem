using ll = long long;
class Solution {
public:
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minInd = -1, maxInd = -1, inValidInd = -1, n = nums.size();

        ll validSubarrays = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                inValidInd = i;

            if (nums[i] == minK)
                minInd = i;
            if (nums[i] == maxK)
                maxInd = i;
            int count = max(min(minInd, maxInd) - inValidInd, 0);
            validSubarrays += count;
        }
        return validSubarrays;
    }
};
