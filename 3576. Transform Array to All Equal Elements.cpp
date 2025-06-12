class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int count1 = 0, countM1 = 0, n = nums.size();
        for (int& x : nums) {
            if (x == 1)
                count1++;
            else
                countM1++;
        }
        if (count1 == 0 || countM1 == 0)
            return true;
        int tempK = k;
        vector<int> tempNums = nums;
        for (int i = 0; k > 0 && i < n - 1; i++) {
            if (nums[i] == -1) {
                nums[i] *= -1;
                countM1 -= (nums[i + 1] == -1) ? 2 : 0;
                nums[i + 1] *= -1;
                k--;
            }
        }
        if (countM1 == 0)
            return true;
        for (int i = 0; tempK > 0 && i < n - 1; i++) {
            if (tempNums[i] == 1) {
                tempNums[i] *= -1;
                count1 -= (tempNums[i + 1] == 1) ? 2 : 0;
                tempNums[i + 1] *= -1;
                tempK--;
            }
        }
        return count1 == 0;
    }
};
