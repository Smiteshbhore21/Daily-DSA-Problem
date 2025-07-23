class Solution {
    public int maximumGain(String s, int x, int y) {
        int n = s.length(), score = 0;
        String maxStr = (x > y) ? "ab" : "ba";
        String minStr = (x < y) ? "ab" : "ba";
        if (maxStr.equals("ab")) {
            minStr = "ba";
        } else {
            minStr = "ab";
        }
        //Pass 1
        String temp_first = removeSubStr(s, maxStr);
        int L = temp_first.length();
        int charRemoved = (n - L);
        score += (charRemoved / 2) * Math.max(x, y);
        //Pass 2
        String temp_second = removeSubStr(temp_first, minStr);
        charRemoved = (L - temp_second.length());
        score += (charRemoved / 2) * Math.min(x, y);
        return score;
    }

    String removeSubStr(String s, String match) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == match.charAt(1) && !st.isEmpty() && st.peek() == match.charAt(0)) {
                st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }

        StringBuilder temp = new StringBuilder();
        while (!st.isEmpty()) {
            temp.append(st.peek());
            st.pop();
        }
        return temp.reverse().toString();
    }
}
