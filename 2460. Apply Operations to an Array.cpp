class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }
        int i = 0;
        for (auto x : nums) {
            if (x != 0)
                nums[i++] = x;
        }
        while (i < n)
            nums[i++] = 0;

        return nums;

        // int n = nums.size(), i = 0;
        // queue<int> qu;
        // for (i; i < n - 1; i++) {
        //     if (nums[i] == 0)
        //         continue;
        //     if (nums[i] == nums[i + 1]) {
        //         qu.push(nums[i] + nums[i + 1]);
        //         i++;
        //     } else if (nums[i] != 0)
        //         qu.push(nums[i]);
        // }
        // if(i==n-1)
        //         qu.push(nums[n-1]);
        // for (int i = 0; i < n; i++) {
        //     if (!qu.empty()) {
        //         nums[i] = qu.front();
        //         qu.pop();
        //     } else {
        //         nums[i] = 0;
        //     }
        // }
        // return nums;
    }
};
