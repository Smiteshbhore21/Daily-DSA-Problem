class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // case 1 : When k == n
        if (k == n) { // only one subarray possible. Select the largest element
            return *max_element(begin(nums), end(nums));
        }

        // case 2 : When k == 1
        int freq[51] = {0};
        for (int& num : nums) {
            freq[num]++;
        }

        if (k == 1) { // every index is one subarray. Find largest element which
                      // appears only once
            for (int num = 50; num >= 0; num--) {
                if (freq[num] == 1) {
                    return num;
                }
            }
            return -1;
        }

        // case 3 : 1 < k < n
        // Notice that only the first and last element are going to be the ones
        // which will appear only in one subarray. Others will be part of more
        // than one subarray always

        int maxResult = -1;
        // So, if nums[0] appeared only at index 0, then it appeared only in one
        // subarray
        if (freq[nums[0]] == 1) {
            maxResult = max(maxResult, nums[0]);
        }

        // Same, if nums[n-1] appeared only at index n-1, then it appeared only
        // in one subarray
        if (freq[nums[n - 1]] == 1) {
            maxResult = max(maxResult, nums[n - 1]);
        }

        return maxResult;
    }
};
