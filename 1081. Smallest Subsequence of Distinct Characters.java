class Solution {
    public String smallestSubsequence(String s) {
        int[] freq = new int[26];
        boolean[] visited = new boolean[26];

        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
        }
        StringBuilder str = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int idx = ch - 'a';

            freq[idx]--;

            if (visited[idx]) {
                continue;
            }

            while (str.length() > 0 && str.charAt(str.length() - 1) > ch
                    && freq[str.charAt(str.length() - 1) - 'a'] > 0) {
                char removed = str.charAt(str.length() - 1);
                visited[removed - 'a'] = false;
                str.deleteCharAt(str.length() - 1);
            }

            str.append(ch);
            visited[idx] = true;
        }

        return str.toString();
    }
}
