class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, n = nums.size();

        for (int& num : nums) {
            sum = (sum + num) % p;
        }

        int target = sum % p;

        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        int curr = 0, result = n;
        mp[curr] = -1;
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;
            int remain = (curr - target + p) % p;
            if (mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }
            mp[curr] = j;
        }
        return result == n ? -1 : result;
    }
};
