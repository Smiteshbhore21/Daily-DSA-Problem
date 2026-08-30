class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        pair<int, int> minMax;

        minMax.first = min_element(begin(nums), end(nums)) - begin(nums);
        minMax.second = max_element(begin(nums), end(nums)) - begin(nums);

        int left = min(minMax.first, minMax.second);
        int right = max(minMax.first, minMax.second);

        return min({left + 1 + n - right, right + 1, n - left});
    }
};
