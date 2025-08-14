class Solution {
    public String largestGoodInteger(String num) {
        String[] valid = { "999", "888", "777", "666", "555", "444", "333", "222", "111", "000" };
        for (String ans : valid) {
            if (num.contains(ans))
                return ans;
        }
        return "";
    }
}

// O(n) --> 
// class Solution {
//     public String largestGoodInteger(String num) {
//         int n = num.length();
//         String ans = "";
//         for (int i = 2; i < n; i++) {
//             if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i - 1) == num.charAt(i - 2)) {
//                 String triple = num.substring(i - 2, i + 1);
//                 if (triple.compareTo(ans) > 0) {
//                     ans = triple;
//                 }
//             }
//         }
//         return ans;
//     }
// }
