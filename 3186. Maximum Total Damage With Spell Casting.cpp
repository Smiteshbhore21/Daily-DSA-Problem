
using ll = long long;
// Botton Up -->
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> freq;
        for (const int& x : power) {
            freq[x]++;
        }
        vector<long long> nums;
        for (auto& it : freq) {
            nums.push_back(it.first);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<ll> t(n, 0);

        ll res = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            ll skip = (i + 1 < n) ? t[i + 1] : 0;
            int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) -
                    nums.begin();
            ll take = nums[i] * freq[nums[i]] + ((j < n) ? t[j] : 0);
            t[i] = max(take, skip);
            res = max(res, t[i]);
        }
        return res;
    }
};

// Memo + Recur
// using ll = long long;
// class Solution {
// public:
//     int n;
//     unordered_map<ll, ll> freq;
//     vector<ll> t;
//     ll solve(vector<ll>& nums, int i) {
//         if (i >= n) {
//             return 0;
//         }
//         if (t[i] != -1)
//             return t[i];
//         ll skip = solve(nums, i + 1);
//         ll j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) -
//                nums.begin();
//         ll take = nums[i] * freq[nums[i]] + solve(nums, j);
//         return t[i] = max(take, skip);
//     }
//     long long maximumTotalDamage(vector<int>& power) {
//         for (const int& x : power) {
//             freq[x]++;
//         }
//         vector<long long> nums;
//         for (auto& it : freq) {
//             nums.push_back(it.first);
//         }
//         sort(nums.begin(), nums.end());
//         n = nums.size();
//         t.assign(n + 1, -1);
//         return solve(nums, 0);
//     }
// };
