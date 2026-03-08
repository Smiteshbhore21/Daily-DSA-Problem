class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }};

// class Solution {
// public:
//     unordered_set<string> st;
//     int n;
//     string ans;
//     string findDifferentBinaryString(vector<string>& nums) {
//         st = unordered_set<string>(nums.begin(), nums.end());
//         n = nums.size();
//         solve("");
//         return ans;
//     }
//     bool solve(string curr) {
//         if (curr.length() == n) {
//             if (!st.count(curr)) {
//                 ans = curr;
//                 return true;
//             }
//             return false;
//         }
//         if (solve(curr + '1'))
//             return true;
//         if (solve(curr + '0'))
//             return true;
//         return false;
//     }
// };

// class Solution {
// public:
//     string ans = "";
//     // unordered_map<string, int> mp;
//     string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums.size();
//         // for (const string& str : nums) {
//         //     mp[str] = 1;
//         // }
//         backtrack(n, nums, "");
//         return ans;
//     }
//     bool backtrack(int& n, vector<string>& nums, string cur) {
//         if (cur.size() == n) {
//             if (find(nums.begin(), nums.end(), cur) == nums.end()) {
//                 ans = cur;
//                 return true;
//             }
//             return false;
//         }
//         cur.push_back('0');
//         if (backtrack(n, nums, cur))
//             return true;
//         cur.pop_back();
//         cur.push_back('1');
//         if (backtrack(n, nums, cur))
//             return true;
//         cur.pop_back();
//         return false;
//     }
// };
