class Solution {
public:
    string ans = "";
    // unordered_map<string, int> mp;
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // for (const string& str : nums) {
        //     mp[str] = 1;
        // }
        backtrack(n, nums, "");
        return ans;
    }
    bool backtrack(int& n, vector<string>& nums, string cur) {
        if (cur.size() == n) {
            if (find(nums.begin(), nums.end(), cur) == nums.end()) {
                ans = cur;
                return true;
            }
            return false;
        }
        cur.push_back('0');
        if (backtrack(n, nums, cur))
            return true;
        cur.pop_back();

        cur.push_back('1');
        if (backtrack(n, nums, cur))
            return true;
        cur.pop_back();

        return false;
    }
};
