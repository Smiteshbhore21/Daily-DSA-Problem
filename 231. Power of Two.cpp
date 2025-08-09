class Solution {
public:
    bool isPowerOfTwo(int n) { 
      return (n > 0) && (n & (n - 1)) == 0; 
    }
};

// O(log(n)) -->
// class Solution {
// public:
//     long long binaryExpo(long long a, long long b) {
//         if (b == 0)
//             return 1;
//         long long half = binaryExpo(a, b / 2);
//         long long res = half * half;
//         if (b % 2 == 1)
//             res *= a;
//         return res;
//     }
//     bool isPowerOfTwo(int n) {
//         if (n < 0) {
//             return false;
//         }
//         long long pow2 = binaryExpo(2, 0);
//         long long i = 1;
//         while (pow2 <= n) {
//             if (pow2 == n)
//                 return true;
//             pow2 = binaryExpo(2, i);
//             i++;
//         }
//         return false;
//     }
// };
