class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxEle = n - 1;
        int maxEleCnt = 0;
        for (int& num : nums) {
            int val = abs(num);
            if (val > maxEle)
                return false;
            else if (val == maxEle)
                maxEleCnt++;

            if (nums[val] < 0) {
                if (val != maxEle)
                    return false;
                else if (maxEleCnt > 2)
                    return false;
            } else
                nums[val] *= -1;
        }
        return true;
    }
};
