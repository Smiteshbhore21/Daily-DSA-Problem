class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(100, 0);
        int maxOccurance = 0;
        for (int& x : nums) {
            freq[x - 1]++;
            maxOccurance = max(maxOccurance, freq[x - 1]);
        }
        int ans = 0;
        for (int& x : freq) {
            if (x == maxOccurance)
                ans += x;
        }
        return ans;
    }
};
