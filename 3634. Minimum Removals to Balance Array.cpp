class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int L = 1;
        int i = 0;
        int j = 0;
        int minEle = nums[0];
        int maxEle = nums[0];

        while (j < n) {
            minEle = nums[i];
            maxEle = nums[j];
            while (i < j && maxEle > (1ll * k * minEle)) {
                i++;
                minEle = nums[i];
            }
            L = max(L, j - i + 1);
            j++;
        }
        return n - L;
    }
};
