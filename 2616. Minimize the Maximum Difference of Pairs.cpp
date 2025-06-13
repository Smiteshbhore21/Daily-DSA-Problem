class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0, end = nums[n - 1], ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int cnt = 0;
            for (int i = 0; i < n;) {
                if (i + 1 < n) {
                    if (mid >= abs(nums[i] - nums[i + 1])) {
                        cnt++;
                        i += 2;
                    } else {
                        i++;
                    }
                }else{
                    i++;
                }
            }
            if (cnt >= p) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
