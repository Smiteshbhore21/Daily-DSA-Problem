class Solution {
    private int[] count;
    private String result = "";

    public String lexGreaterPermutation(String s, String target) {
        count = new int[26];
        result = "";

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        StringBuilder curr = new StringBuilder();

        solve(curr, target, 0, false);

        return result;
    }

    private boolean solve(StringBuilder curr, String target, int i, boolean greater) {

        if (i == target.length()) {
            if (greater) {
                result = curr.toString();
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
