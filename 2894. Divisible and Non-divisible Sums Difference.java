// O(1) --->
class Solution {
    public int differenceOfSums(int n, int m) {
        // int k = n / m;                       //total dividing terms
        // int num2 = m * (k * (k + 1) / 2);    //sum of all dividing terms
        // int num1 = (n * (n + 1) / 2) - num2; //sum of all non dividing terms
        return (n * (n + 1) / 2) - m * (n / m) * ((n / m) + 1);
        // return num1 - num2;
    }
}

// O(N) --->
// class Solution {
//     public int differenceOfSums(int n, int m) {
//         int num1 = 0, num2 = 0;
//         for (int i = 1; i <= n; i++) {
//             if (i % m == 0) {
//                 num2 += i;
//             } else {
//                 num1 += i;
//             }
//         }
//         return num1 - num2;
//     }
// }
