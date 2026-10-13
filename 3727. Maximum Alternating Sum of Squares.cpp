class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        for (int& num : nums) {
            num = abs(num);
        }

        int totalNeg = n / 2;

        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int num : nums) {
            if (totalNeg) {
                result -= (num * num);
                totalNeg--;
            } else {
                result += (num * num);
            }
        }

        return result;
    }
};
