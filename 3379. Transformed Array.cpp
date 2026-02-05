class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = 1;
            if (nums[i] > 0) {
                int idx = (nums[i] + i) % n;
                result[i] = nums[idx];
            } else if (nums[i] < 0) {
                int idx = ((nums[i] % n) + i) % n;
                if(idx < 0){
                    idx += n;
                }
                result[i] = nums[idx];
            } else {
                result[i] = nums[i];
            }
        }
        return result;
    }
};
