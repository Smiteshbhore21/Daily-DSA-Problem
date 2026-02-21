class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        unordered_set<int> primeNums = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (primeNums.count(setBits)) {
                result++;
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     int countPrimeSetBits(int left, int right) {
//         int result = 0;
//         for (int i = left; i <= right; i++) {
//             int setBits = __builtin_popcount(i);
//             if (isPrime(setBits)) {
//                 result++;
//             }
//         }
//         return result;
//     }
//     bool isPrime(int& val) {
//         if (val < 2)
//             return false;
//         for (int i = 2; i <= sqrt(val); i++) {
//             if (val % i == 0)
//                 return false;
//         }
//         return true;
//     }
// };
