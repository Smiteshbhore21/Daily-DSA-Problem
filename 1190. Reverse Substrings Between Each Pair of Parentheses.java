class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();

        StringBuilder str = new StringBuilder(s);
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else if (s.charAt(i) == ')') {
                int top = stack.peek();
                stack.pop();
                reverseStr(str, top + 1, i - 1);
            }
        }

        StringBuilder result = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            if (ch == '(' || ch == ')')
                continue;
            result.append(ch);
        }

        return result.toString();
    }

    public void reverseStr(StringBuilder str, int start, int end) {
        while (start < end) {
            char temp = str.charAt(start);
            str.setCharAt(start, str.charAt(end));
            str.setCharAt(end, temp);
            start++;
            end--;
        }
    }
}
