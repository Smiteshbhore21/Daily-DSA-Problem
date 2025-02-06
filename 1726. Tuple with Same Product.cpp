class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        map<int, int> prodMap;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                prodMap[nums[i] * nums[j]]++;
            }
        }
        for (const auto& key : prodMap) {
            int count = key.second;
            if (count >= 2) {
                int comb = (count * (count - 1)) / 2;
                ans = ans + comb * 8;
            }
        }
        return ans;
    }
};
