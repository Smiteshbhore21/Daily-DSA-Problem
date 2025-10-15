class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        int currRun = 1;
        int prevRun = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                currRun++;
            } else {
                prevRun = currRun;
                currRun = 1;
            }
            k = max(k, min(prevRun, currRun));
            k = max(k, currRun / 2);
        }
        return k;
    }
};
