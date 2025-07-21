class Solution {
    public String makeFancyString(String s) {
        int n = s.length();
        if (n < 3) {
            return s;
        }
        StringBuilder ans = new StringBuilder("");
        ans.append(s.charAt(0));
        ans.append(s.charAt(1));
        for (int i = 2; i < n; i++) {
            if (s.charAt(i - 2) == s.charAt(i - 1) && s.charAt(i - 1) == s.charAt(i)) {
                continue;
            }
            ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}
