class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();

        int open = 0;
        int close = 0;

        int result = 0;
        for (int i = 0; i < n; i++) {

            open = s.charAt(i) == '(' ? open + 1 : open;
            close = s.charAt(i) == ')' ? close + 1 : close;

            if (close > open) {
                open = 0;
                close = 0;
            } else if (close == open)
                result = Math.max(result, open + close);
        }

        open = 0;
        close = 0;
        for (int i = n - 1; i >= 0; i--) {

            open = s.charAt(i) == '(' ? open + 1 : open;
            close = s.charAt(i) == ')' ? close + 1 : close;

            if (close < open) {
                open = 0;
                close = 0;
            } else if (close == open)
                result = Math.max(result, open + close);
        }

        return result;
    }
}
