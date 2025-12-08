class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int target = i * i;
            int left = 1;
            int right = i - 1;

            while (left < right) {
                int sum = left * left + right * right;

                if (sum == target) {
                    cnt += 2;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int countTriples(int n) {
//         unordered_set<int> allSqr;
//         for (int i = 1; i <= n; i++) {
//             allSqr.insert(i * i);
//         }
//         int cntST = 0;
//         for (int i = 1; i < n; i++) {
//             for (int j = 2; j <= n; j++) {
//                 if (allSqr.count((i * i) + (j * j))) {
//                     cntST++;
//                 }
//             }
//         }
//         return cntST;
//     }
// };
