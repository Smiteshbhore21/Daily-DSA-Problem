class Solution {
    using ll = long long;

public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        ll count = 0, pairs = 0;
        unordered_map<int, int> freqCount;

        while (j < n) {
            pairs += freqCount[nums[j]];
            freqCount[nums[j]]++;
            while (pairs >= k) {
                count += (n - j);
                freqCount[nums[i]]--;
                pairs -= freqCount[nums[i]];
                i++;
            }
            j++;
        }

        return count;
    }
};
