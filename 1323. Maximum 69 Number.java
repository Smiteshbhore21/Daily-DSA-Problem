class Solution {
    public int maximum69Number(int num) {
        Stack<Integer> s = new Stack<>();
        int temp = num;
        while (temp != 0) {
            s.push(temp % 10);
            temp /= 10;
        }
        num = 0;
        while (!s.isEmpty()) {
            int top = s.pop();
            if (top == 6 && temp == 0) {
                num = (num * 10) + 9;
                temp = 1;
            } else {
                num = (num * 10) + top;
            }
        }
        return num;
    }
}

// C++ -->
// class Solution {
// public:
//     int maximum69Number(int num) {
//         int ind6 = 0;
//         int temp = num, i = 0;
//         while (temp) {
//             int digit = temp % 10;
//             if (digit == 6) {
//                 ind6 = i;
//             }
//             temp /= 10;
//             i++;
//         }
//         temp = num, i = 0;
//         num = 0;
//         while (temp) {
//             int digit = temp % 10;
//             if (ind6 == i) {
//                 num = (num * 10) + 9;
//             } else {
//                 num = (num * 10) + digit;
//             }
//             temp /= 10;
//             i++;
//         }
//         temp = num, num = 0;
//         while (temp) {
//             int digit = temp % 10;
//             num = (num * 10) + digit;
//             temp /= 10;
//         }
//         return num;
//     }
// };
