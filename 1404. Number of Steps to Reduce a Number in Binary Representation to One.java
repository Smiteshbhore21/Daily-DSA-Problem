class Solution {
    public int numSteps(String s) {
        int n = s.length();

        int ops = 0, carry = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (((s.charAt(i) - '0') + carry) % 2 == 1) {
                ops += 2;
                carry = 1;
            } else
                ops += 1;
        }
        return ops + carry;
    }
}

// O(n^2) --> 
// class Solution {
//     public int numSteps(String s) {
//         int ops = 0;
//         while (s.length() > 1) {
//             int n = s.length() - 1;
//             if (s.charAt(n) == '1') {
//                 s = addOne(s);
//             } else {
//                 s = s.substring(0, n);
//             }
//             ops++;
//         }
//         return ops;
//     }
//     public String addOne(String s) {
//         StringBuilder sb = new StringBuilder(s);
//         int i = sb.length() - 1;
//         while (i >= 0 && sb.charAt(i) == '1') {
//             sb.setCharAt(i, '0');
//             i--;
//         }
//         if (i < 0) {
//             sb.insert(0, '1');
//         } else {
//             sb.setCharAt(i, '1');
//         }
//         return sb.toString();
//     }
// }
