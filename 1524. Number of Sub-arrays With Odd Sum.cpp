class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7, prefix = 0, ans = 0, even = 1, odd = 0;
        for (int x : arr) {
            prefix += x;
            if (prefix % 2 == 1) {
                ans += even;
                odd++;
            } else {
                ans += odd;
                even++;
            }
            ans %= mod;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> allSub;
//         vector<int> allSums;
//         allSub.push_back(arr);
//         for (int i = 0; i < n; i++) {
//             vector<int> temp;
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += arr[j];
//                 temp.push_back(arr[j]);
//                 allSub.push_back(temp);
//                 allSums.push_back(sum);
//             }
//         }

//         int oddSumCount = 0;
//         for (int x : allSums)
//             if (x % 2 != 0)
//                 oddSumCount++;
//         return oddSumCount % (1000000000 + 7);
//     }
// };
