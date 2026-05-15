class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int result = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            result = min(nums[mid], result);
            if (nums[l] <= nums[mid] && nums[r] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};
