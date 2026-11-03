class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(begin(nums), end(nums));

        int result = 0;
        for (int& num : nums) {
            result += (maxEle - num);
        }
        
        return result;
    }
};
