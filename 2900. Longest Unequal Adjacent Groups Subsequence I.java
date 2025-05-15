class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        int n = words.length, ord = groups[0];
        ans.add(words[0]);
        for (int i = 1; i < n; i++) {
            if (groups[i] != ord) {
                ans.add(words[i]);
                ord = groups[i];
            }
        }
        return ans;
    }
}
