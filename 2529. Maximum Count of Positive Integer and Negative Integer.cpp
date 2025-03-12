class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int s = 0, n = nums.size(), e = n - 1, pos = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= 0) {
                e = mid - 1;
            } else if (nums[mid] < 0)
                s = mid + 1;
        }
        pos = s;
        e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > 0) {
                e = mid - 1;
            } else if (nums[mid] <= 0)
                s = mid + 1;
        }
        int ans = max(n - s, pos);
        return ans;
    }
};
