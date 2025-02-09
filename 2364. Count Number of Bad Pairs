class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size(), goodPairs = 0;
        map<long, long> posVal;
        for (int i = 0; i < n; i++) {
            int key = i - nums[i];
            goodPairs += posVal[key]++;
        }
        return (n * (n - 1) / 2) - goodPairs;
    }
};
