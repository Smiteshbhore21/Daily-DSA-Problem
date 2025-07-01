class Solution {
    public int possibleStringCount(String word) {
        int ans = 1, n = word.length();
        int freq = 1;
        for (int i = 1; i < n; i++) {
            if (word.charAt(i - 1) != word.charAt(i)) {
                ans += (freq - 1);
                freq = 1;
            } else {
                freq++;
            }
        }
        ans += (freq - 1);
        return ans;
    }
}
