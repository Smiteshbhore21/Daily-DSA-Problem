class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0, suffix = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            suffix -= nums[i];
            if (nums[i] == 0 && prefix == suffix)
                ans += 2;
            else if (nums[i] == 0 &&
                     (prefix == suffix + 1 || prefix + 1 == suffix))
                ans += 1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int countValidSelections(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n, 0), suffix(n, 0);
//         prefix[0] = nums[0];
//         suffix[n - 1] = nums[n - 1];
//         for (int i = 1, j = n - 2; i < n; i++, j--) {
//             prefix[i] = prefix[i - 1] + nums[i];
//             suffix[j] = suffix[j + 1] + nums[j];
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0 && prefix[i] == suffix[i])
//                 ans += 2;
//             else if (nums[i] == 0 &&
//                      (prefix[i] == suffix[i] + 1 || prefix[i] + 1 ==
//                      suffix[i]))
//                 ans += 1;
//         }
//         return ans;
//     }
// };
