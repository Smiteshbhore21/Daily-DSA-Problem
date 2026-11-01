class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());

        int result = 0;
        for (int num : nums) {
            result += (num - minEle);
        }

        return result;
    }
};
