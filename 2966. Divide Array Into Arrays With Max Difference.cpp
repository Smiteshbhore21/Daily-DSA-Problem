// O(n + max_element)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        mx++;
        vector<int> mp(mx, 0);
        for (const int& x : nums)
            mp[x]++;
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i = 0; i < mx;) {
            while (mp[i] && temp.size() != 3) {
                temp.push_back(i);
                mp[i]--;
                if (temp.size() == 3) {
                    if (temp[2] - temp[1] > k || temp[1] - temp[0] > k ||
                        temp[2] - temp[0] > k)
                        return {};
                }
            }
            if (temp.size() != 3) {
                i++;
                continue;
            }
            ans.push_back(temp);
            temp.clear();
            if (mp[i] == 0)
                i++;
        }
        return ans;
    }
};

// O(n log(n))
// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         int n = nums.size();
//         for (int i = 0; i < n; i += 3) {
//             if (nums[i + 2] - nums[i + 1] > k || nums[i + 1] - nums[i] > k ||
//                 nums[i + 2] - nums[i] > k)
//                 return {};
//             ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
//         }
//         return ans;
//     }
// };

// O(n log(n)) + With Map
// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         map<int, int> mp;
//         for (const int& x : nums)
//             mp[x]++;
//         vector<vector<int>> ans;
//         int n = nums.size();
//         vector<int> temp;
//         for (map<int, int>::iterator it = mp.begin(); it != mp.end();) {
//             while (it->second && temp.size() != 3) {
//                 temp.push_back(it->first);
//                 it->second--;
//                 if (temp.size() == 3) {
//                     if (temp[2] - temp[1] > k || temp[1] - temp[0] > k ||
//                         temp[2] - temp[0] > k)
//                         return {};
//                 }
//             }
//             if (temp.size() != 3) {
//                 it++;
//                 continue;
//             }
//             ans.push_back(temp);
//             temp.clear();
//             if (it->second == 0)
//                 it++;
//         }
//         return ans;
//     }
// };
