class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0, a = max(num1, num2), b = min(num1, num2);
        while (a && b) {
            ops += (a / b);
            a %= b;
            swap(a, b);
        }
        return ops;
    }
};

// class Solution {
// public:
//     int countOperations(int num1, int num2) {
//         int ops = 0;
//         while (num1 != 0 && num2 != 0) {
//             if (num1 >= num2) {
//                 num1 -= num2;
//             } else {
//                 num2 -= num1;
//             }
//             ops++;
//         }
//         return ops;
//     }
// };
