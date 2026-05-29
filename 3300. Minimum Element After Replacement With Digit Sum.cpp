class Solution {
public:
    int minElement(vector<int>& nums) {
        int minEle = INT_MAX;
        for (auto& num : nums) {
            minEle = min(digitSum(num), minEle);
        }

        return minEle;
    }
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum = sum + (num % 10);
            num /= 10;
        }
        return sum;
    }
};
