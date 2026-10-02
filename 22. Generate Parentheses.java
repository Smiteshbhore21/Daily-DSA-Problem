class Solution {
    List<String> result;

    public List<String> generateParenthesis(int n) {
        result = new ArrayList<>();
        solve(n, 0, 0, new StringBuilder(""));
        return result;
    }

    void solve(int n, int open, int close, StringBuilder curr_str) {
        if (curr_str.length() == n * 2) {
            result.add(curr_str.toString());
            return;
        }
        if (open < n) {
            solve(n, open + 1, close, curr_str.append('('));
            curr_str.deleteCharAt(curr_str.length() - 1);
        }
        if (close < open) {
            solve(n, open, close + 1, curr_str.append(')'));
            curr_str.deleteCharAt(curr_str.length() - 1);
        }
        return;
    }
}
