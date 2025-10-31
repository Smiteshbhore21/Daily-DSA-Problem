class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 2);
        vector<int> ans;
        for (const int& num : nums) {
            freq[num]++;
            if (freq[num] == 2)
                ans.push_back(num);
        }
        return ans;
    }
};
