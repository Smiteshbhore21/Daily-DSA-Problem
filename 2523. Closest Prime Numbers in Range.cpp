class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Sieve Algorithm
        vector<int> prime(right + 1, true), ans{-1, -1};
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i*i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }
        int minDif = INT_MAX, prev = -1;
        for (int i = left; i <= right; i++) {
            if (prime[i]){
                if (prev == -1)
                    prev = i;
                else {
                    if(i - prev < minDif){
                        ans[0] = prev;
                        ans[1] = i;
                        minDif = i-prev;
                    }
                    prev = i;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> closestPrimes(int left, int right) {
//         vector<int> primeInRange, ans{-1, -1};
//         for (int i = left; i <= right; i++) {
//             if (isPrime(i))
//                 primeInRange.push_back(i);
//         }
//         int n = primeInRange.size(), minDis = INT_MAX;
//         if (n < 2)
//             return vector<int>{-1, -1};
//         for (int i = 1; i < n; i++) {
//             if (minDis > primeInRange[i] - primeInRange[i - 1]) {
//                 minDis = primeInRange[i] - primeInRange[i - 1];
//                 left = primeInRange[i - 1];
//                 right = primeInRange[i];
//             }
//         }
//         ans[0] = left;
//         ans[1] = right;
//         return ans;
//     }
//     bool isPrime(int n) {
//         if (n < 2)
//             return false;
//         for (int i = 2; i <= sqrt(n); i++) {
//             if (n % i == 0)
//                 return false;
//         }
//         return true;
//     }
// };
