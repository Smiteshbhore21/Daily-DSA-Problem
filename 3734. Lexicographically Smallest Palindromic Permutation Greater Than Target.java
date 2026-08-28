class Solution {
    private int[] count;
    private String result = "";
    private char oddChar;

    public String lexPalindromicPermutation(String s, String target) {

        count = new int[26];
        result = "";

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        oddChar = '%';

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] % 2 == 1) {

                if (oddChar != '%') {
                    return "";
                }

                oddChar = ch;
            }

            count[ch - 'a'] /= 2;
        }

        StringBuilder curr = new StringBuilder();

        boolean found = solve(curr, target, 0, false);

        if (!found) {
            return "";
        }

        String right = new StringBuilder(result).reverse().toString();

        return oddChar != '%'
                ? result + oddChar + right
                : result + right;
    }

    private boolean solve(StringBuilder curr, String target, int i, boolean greater) {
        int halfLength = target.length() / 2;

        if (i == halfLength) {

            String left = curr.toString();
            String right = new StringBuilder(left).reverse().toString();

            String candidate;

            if (oddChar != '%') {
                candidate = left + oddChar + right;
            } else {
                candidate = left + right;
            }

            if (candidate.compareTo(target) > 0) {
                result = left;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0) {
                continue;
            }

            if (!greater && ch < target.charAt(i)) {
                continue;
            }

            curr.append(ch);
            count[ch - 'a']--;

            boolean isGreater = greater || ch > target.charAt(i);

            if (solve(curr, target, i + 1, isGreater)) {
                return true;
            }

            curr.deleteCharAt(curr.length() - 1);
            count[ch - 'a']++;
        }

        return false;
    }
}
