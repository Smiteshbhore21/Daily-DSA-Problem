int M = 1e9 + 7;
class Solution {
public:
    vector<int> powers, ans;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }

        for (vector<int>& q : queries) {
            int start = q[0];
            int end = q[1];
            int rangeMulti = 1;
            for(int i = start; i <= end; i++){
                rangeMulti = (1LL * rangeMulti * powers[i]) % M;
            }
            ans.push_back(rangeMulti);
        }

        return ans;
    }
};

// ModInverse -->
// int M = 1e9 + 7;
// class Solution {
// public:
//     vector<int> powers, ans;
//     vector<long long> prefix;

//     long long binaryExpo(long long a, long long b) {
//         if (b == 0)
//             return 1;
//         a %= M;
//         long long half = binaryExpo(a, b / 2);
//         long long res = (half * half) % M;
//         if (b % 2 == 1)
//             res = (res * a) % M;
//         return res;
//     }

//     long long modinv(long long a) { 
//         return binaryExpo(a , M - 2); 
//     }

//     vector<int> productQueries(int n, vector<vector<int>>& queries) {
//         long long sum = 1;
//         for (int i = 0; i < 32; i++) {
//             if (n & (1 << i)) {
//                 powers.push_back(1 << i);
//                 sum = sum * (1 << i) % M;
//                 prefix.push_back(sum);
//             }
//         }

//         for (vector<int>& q : queries) {
//             int rangeMulti = (q[0] - 1 >= 0)
//                                  ? (prefix[q[1]] * modinv(prefix[q[0] - 1])) % M
//                                  : prefix[q[1]];
//             ans.push_back(rangeMulti);
//         }

//         return ans;
//     }
// };
