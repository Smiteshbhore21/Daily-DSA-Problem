class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        nth_element(begin(nums), begin(nums) + (n / 2), end(nums));

        int count = 0;
        int selected = nums[n / 2];

        for (int i = 0; i < n; i++)
            count = count + abs(selected - nums[i]);

        return count;
    }
};
