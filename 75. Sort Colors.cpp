class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int mp[3] = {0};
        // int n = nums.size();
        // for (int& x : nums) {
        //     mp[x]++;
        // }
        // int idx = 0;
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < mp[i]; j++) {
        //         nums[idx] = i;
        //         idx++;
        //     }
        // }
        int s = 0, e = nums.size() - 1, mid = 0;

        while (mid <= e) {
            if (nums[mid] == 0) {
                swap(nums[s++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[e--]);
            }
        }
    }
};
