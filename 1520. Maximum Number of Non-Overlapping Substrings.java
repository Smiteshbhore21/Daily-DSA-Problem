class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[] start = new int[26];
        int[] end = new int[26];
        Arrays.fill(start, -1);

        char[] str = s.toCharArray();

        for (int i = 0; i < n; i++) {
            int idx = str[i] - 'a';

            if (start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        boolean[] isValid = new boolean[26];
        for (int i = 0; i < 26; i++) {
            if (start[i] != -1)
                isValid[i] = true;
        }

        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;

            for (int i = start[c]; i <= end[c]; i++) {
                if (start[str[i] - 'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }
                end[c] = Math.max(end[c], end[str[i] - 'a']);
            }
        }

        int lastTakenStart = Integer.MAX_VALUE;
        List<String> result = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            int idx = str[i] - 'a';

            if (!isValid[idx])
                continue;

            if (i == start[idx] && end[idx] < lastTakenStart) {
                result.add(s.substring(i, end[idx] + 1));
                lastTakenStart = i;
            }
        }

        return result;
    }
}
