class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int start = INT_MAX, end = INT_MIN, ans = 0;
        for (int& x : nums) {
            if (x < start)
                start = x;

            if (x > end)
                end = x;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isRobbery(mid, nums, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    bool isRobbery(int& mid, vector<int>& nums, int& k) {
        int houseRobbed = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                houseRobbed++;
                i++;
            }
            if (houseRobbed >= k)
                return true;
        }
        return false;
    }
};
