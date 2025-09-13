class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            freq[s.charAt(i) - 'a']++;
        }
        int maxVowel = 0, maxConso = 0;
        for (int i = 0; i < 26; i++) {
            if ((char) (i + 'a') == 'a' || (char) (i + 'a') == 'e' || (char) (i + 'a') == 'i' || (char) (i + 'a') == 'o'
                    || (char) (i + 'a') == 'u') {
                maxVowel = Math.max(maxVowel, freq[i]);
            } else {
                maxConso = Math.max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
}
