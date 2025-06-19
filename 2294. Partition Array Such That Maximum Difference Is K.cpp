// O(n+m) 
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(), maxVal = *max_element(nums.begin(), nums.end());
        maxVal++;
        vector<int> freq(maxVal, 0);
        for (const int& x : nums) {
            freq[x]++;
        }
        int l = 0, r = 0, ans = 0;
        while (l < maxVal) {
            if (freq[l] == 0 and freq[r] == 0) {
                l++, r++;
            } else {
                while (r < maxVal && r - l <= k) {
                    if (freq[r] != 0)
                        freq[r]--;
                    else
                        r++;
                }
                ans++;
                l = r;
            }
        }
        return ans;
    }
};

// O(nlog(n))
// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int l = 0, r = 0, ans = 0;
//         while (l < n) {
//             while (r < n && nums[r] - nums[l] <= k) {
//                 r++;
//             }
//             ans++;
//             l = r;
//         }
//         return ans;
//     }
// };
