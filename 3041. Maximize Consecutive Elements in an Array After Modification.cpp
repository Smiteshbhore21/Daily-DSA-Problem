// Bottom-up
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        n = nums.size();

        memo.assign(n + 1, vector<int>(2, -1));

        int result = 1;
        for (int i = n - 1; i >= 0; i--) {

            for (int inc = 0; inc < 2; inc++) {
                int currVal = nums[i] + inc;

                int j = findMethod(i + 1, currVal + 1, nums);
                int len = 1;

                if (j != -1) {
                    len = max(len, 1 + memo[j][0]);
                }

                j = findMethod(i + 1, currVal, nums);

                if (j != -1) {
                    len = max(len, 1 + memo[j][1]);
                }

                memo[i][inc] = len;
                result = max(result, memo[i][inc]);
            }
        }

        return result;
    }

    int findMethod(int start, int target, vector<int>& nums) {
        int j =
            lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if (j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }
};

// Recursion + Memo -->
// class Solution {
// public:
//     int n;
//     vector<vector<int>> memo;
//     int maxSelectedElements(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         n = nums.size();
//         memo.assign(n + 1, vector<int>(2, -1));
//         int result = 1;
//         for (int i = 0; i < n; i++) {
//             result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
//         }
//         return result;
//     }
//     int findMethod(int start, int target, vector<int>& nums) {
//         int j =
//             lower_bound(begin(nums) + start, end(nums), target) - begin(nums);
//         if (j < n && nums[j] == target) {
//             return j;
//         }
//         return -1;
//     }
//     int solve(int i, int inc, vector<int>& nums) {
//         int currVal = nums[i] + inc;
//         if (memo[i][inc] != -1)
//             return memo[i][inc];
//         int j = findMethod(i + 1, currVal + 1, nums);
//         int len = 1;
//         if (j != -1) {
//             len = max(len, 1 + solve(j, 0, nums));
//         }
//         j = findMethod(i + 1, currVal, nums);
//         if (j != -1) {
//             len = max(len, 1 + solve(j, 1, nums));
//         }
//         return memo[i][inc] = len;
//     }
// };
