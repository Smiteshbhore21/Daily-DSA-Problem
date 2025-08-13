class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        long long pow3 = 1;
        while (pow3 <= n) {
            if (pow3 == n)
                return true;
            pow3 = pow3 * 3;
        }
        return false;
    }
};

// Approuch 1 -->
// class Solution {
// private:
//    static vector<long long> powers3;

// public:
//     Solution() {
//         if (powers3.empty()) {
//             for (int i = 0; i < 21; i++) {
//                 if (powers3.empty())
//                     powers3.push_back(1);
//                 else
//                     powers3.push_back(powers3.back() * 3);
//             }
//         }
//     }

//     bool isPowerOfThree(int n) {
//         if (n <= 0)
//             return false;

//         for (long long& x : powers3) {
//             if (n == x)
//                 return true;
//             if (n < x)
//                 return false;
//         }
//         return false;
//     }
// };

// vector<long long> Solution::powers3;
