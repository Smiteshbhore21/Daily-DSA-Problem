class Solution {
    public int scoreOfParentheses(String s) {
        int n = s.length();

        Deque<Integer> st = new ArrayDeque<>();

        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                st.push(score);
                score = 0;
            } else {
                int back = st.peek();
                if (s.charAt(i - 1) == '(') {
                    score = back + 1;
                } else {
                    score = back + (2 * score);
                }
                st.pop();
            }
        }

        return score;
    }
}
