class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p = false, q = false;
        if (nums[0] > nums[1])
            return false;
        int n = nums.size();
        int decCnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                p = true;
            } else if (nums[i - 1] > nums[i]) {
                decCnt++;
                if (decCnt > 1 && p)
                    return false;
                q = true;
                p = false;
            } else {
                return false;
            }
        }
        return p && q;
    }
};
