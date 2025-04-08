class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> numCount;
        set<int> dupli;
        int n = nums.size(), ans = 0;
        for (int& x : nums) {
            numCount[x]++;
            if (numCount[x] > 1)
                dupli.insert(x);
        }
        for (int i = 0; i < n - 2; i += 3) {
            if (dupli.empty())
                break;
            ans++;
            numCount[nums[i]]--, numCount[nums[i + 1]]--,
                numCount[nums[i + 2]]--;
            if (numCount[nums[i]] <= 1)
                dupli.erase(nums[i]);

            if (numCount[nums[i + 1]] <= 1)
                dupli.erase(nums[i + 1]);

            if (numCount[nums[i + 2]] <= 1)
                dupli.erase(nums[i + 2]);
        }
        if (!dupli.empty())
            ans++;
        return ans;
    }
};
