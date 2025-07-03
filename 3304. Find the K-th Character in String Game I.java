// O(log(k-1)) --> 
class Solution {
    public char kthCharacter(int k) {
        return (char) ('a' + Integer.bitCount(k - 1));

    }
}

// O(k) --> 
// class Solution {
//     public char kthCharacter(int k) {
//         StringBuilder s = new StringBuilder("a");
//         while (s.length() <= k) {
//             StringBuilder toAppend = new StringBuilder("");
//             for (int i = 0; i < s.length(); i++) {
//                 if (s.charAt(i) == 'z') {
//                     toAppend.append('a');
//                 } else {
//                     toAppend.append((char)(s.charAt(i) + 1));
//                 }
//             }
//             s.append(toAppend);
//         }
//         return s.charAt(k - 1);
//     }
// }
