class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size(), lessCount = 0, greaterCount = 0, pivotCount = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                lessCount++;
            else if (nums[i] > pivot)
                greaterCount++;
            else
                pivotCount++;
        }
        int i = 0, j = lessCount, k = j + pivotCount;
        for(int l = 0; l<n; l++){
            if (nums[l] < pivot)
                ans[i++] = nums[l];
            else if (nums[l] > pivot)
                ans[k++] = nums[l];
            else
                ans[j++] = pivot;
        }
        return ans;

        // vector<int> lessThanPivot, greaterThanPivot;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] < pivot)
        //         lessThanPivot.push_back(nums[i]);
        //     else if (nums[i] > pivot)
        //         greaterThanPivot.push_back(nums[i]);
        // }
        // int index = 0;
        // for (int x : lessThanPivot) {
        //     nums[index++] = x;
        // }
        // int same = lessThanPivot.size() + greaterThanPivot.size();
        // for (int i = 0; i < n-same; i++) {
        //     nums[index++] = pivot;
        // }
        // for (int x : greaterThanPivot) {
        //     nums[index++] = x;
        // }
        // return nums;
    }
};
