class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> digitSums, afterSorted(nums);

        sort(begin(afterSorted), end(afterSorted), [&](int num1, int num2) {
            int digitSum1 = digitSum(num1);
            int digitSum2 = digitSum(num2);

            if (digitSum1 != digitSum2) {
                return digitSum1 < digitSum2;
            }

            return num1 < num2;
        });

        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if (currVal == expectedVal)
                continue;

            int idx = valToIdx[expectedVal];
            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;
            result++;
        }

        return result;
    }

    int digitSum(int n) {
        int sum = 0;

        while (n) {
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }
};
