class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = INT_MAX;
        int i = 0;
        for (const int& num : nums) {
            if (num == target)
                result = min(result, abs(i - start));
            i++;
        }
        return result;
    }
};
