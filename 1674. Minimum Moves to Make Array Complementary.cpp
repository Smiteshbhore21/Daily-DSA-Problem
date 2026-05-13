class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - i - 1];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            diff[minVal] += (-1);
            diff[maxVal + 1] -= (-1);

            diff[a + b] += (-1);
            diff[a + b + 1] -= (-1);
        }

        int result = INT_MAX;
        for (int i = 2; i <= 2 * limit; i++) {
            diff[i] += diff[i - 1];

            result = min(result, diff[i]);
        }
        return result;
    }
};
