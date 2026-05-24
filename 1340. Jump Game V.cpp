class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (pair<int, int>& it : vec) {
            int val = it.first;
            int i = it.second;
            int result = 1;

            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i])
                    break;
                result = max(result, 1 + dp[j]);
            }
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i])
                    break;
                result = max(result, 1 + dp[j]);
            }

            dp[i] = result;
        }

        return *max_element(begin(dp), end(dp));
    }
};

// Recursion + Memo(O(n * d)) -->
// class Solution {
// public:
//     int n;
//     vector<int> memo;
//     int solve(vector<int>& arr, int i, int d) {
//         int result = 1;
//         if (memo[i] != -1)
//             return memo[i];
//         // Left
//         for (int j = i - 1; j >= max(0, i - d); j--) {
//             if (arr[j] >= arr[i])
//                 break;
//             result = max(result, 1 + solve(arr, j, d));
//         }
//         // Right
//         for (int j = i + 1; j <= min(n - 1, i + d); j++) {
//             if (arr[j] >= arr[i])
//                 break;
//             result = max(result, 1 + solve(arr, j, d));
//         }
//         return memo[i] = result;
//     }
//     int maxJumps(vector<int>& arr, int d) {
//         n = arr.size();
//         memo.resize(n + 1, -1);
//         int result = 1;
//         for (int i = 0; i < n; i++) {
//             result = max(result, solve(arr, i, d));
//         }
//         return result;
//     }
// };
