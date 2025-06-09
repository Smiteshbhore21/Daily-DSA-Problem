
class Solution {
public:
    int count(long long curr, long long next, int n) {
        long long countNum = 0;
        while (curr <= n) {
            countNum += (next - curr);
            curr = (1ll * curr * 10);
            next = (1ll * next * 10);
            next = min(next, (long long)n + 1);
        }
        return countNum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int countNum = count(curr, curr + 1, n);
            if (countNum <= k) {
                curr++;
                k -= countNum;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};

// O(K) --> Works for upto 1e8
// class Solution {
// public:
//     void solve(int curr, int& n, int& k, int& res, int& count) {
//         if (curr > n)
//             return;
//         if (count == k)
//             return;
//         count++;
//         res = curr;
//         if (count == k)
//             return;
//         for (int i = 0; i <= 9; i++) {
//             long long newNum = (1ll * curr * 10) + i;
//             if (newNum > n)
//                 return;
//             solve(newNum, n, k, res, count);
//         }
//         return;
//     }
//     int findKthNumber(int n, int k) {
//         int result = 0, count = 0;
//         for (int i = 1; i <= 9; i++) {
//             solve(i, n, k, result, count);
//         }
//         return result;
//     }
// };
