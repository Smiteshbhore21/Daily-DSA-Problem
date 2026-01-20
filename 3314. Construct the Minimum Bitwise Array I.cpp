class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            bool found = false;
            for (int bit = 0; bit < 32; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    int prev = bit - 1;
                    int x = nums[i] ^ (1 << prev);
                    ans[i] = x;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> minBitwiseArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         for (int i = 0; i < n; i++) {
//             bool found = false;
//             for (int x = 0; x < nums[i]; x++) {
//                 if ((x | (x + 1)) == nums[i]){
//                     ans[i] = x;
//                     found  = true;
//                     break;
//                 }
//             }
//             if(!found){
//                 ans[i] = -1;
//             }
//         }
//         return ans;
//     }
// };
