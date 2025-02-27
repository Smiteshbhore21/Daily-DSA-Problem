class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size(), maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int cur = 2; cur < n; cur++) {
            int start = 0, end = cur - 1;
            while (start < end) {
                int sum = arr[start] + arr[end];
                if (sum < arr[cur])
                    start++;
                else if (sum > arr[cur])
                    end--;
                else {
                    dp[end][cur] = dp[start][end] + 1;
                    maxLen = max(maxLen, dp[end][cur]);
                    start++;
                    end--;
                }
            }
        }

        return maxLen == 0 ? 0 : maxLen + 2;

        // unordered_set<int> uset;
        // int n = arr.size(), maxCount = 0;
        // for (int x : arr)
        //     uset.insert(x);
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (uset.find(arr[i] + arr[j]) != uset.end()) {
        //             vector<int> fibo;
        //             fibo.push_back(arr[i]);
        //             fibo.push_back(arr[j]);
        //             int prev = 0, curr = 1;
        //             while (uset.find(fibo[prev] + fibo[curr]) != uset.end())
        //             {
        //                 fibo.push_back(fibo[prev] + fibo[curr]);
        //                 prev++, curr++;
        //             }
        //             maxCount = max(maxCount , int(fibo.size()));
        //         }
        //     }
        // }
        // return maxCount;
    }
};
