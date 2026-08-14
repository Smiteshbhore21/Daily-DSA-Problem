class Solution {
    public int maximumLengthSubstring(String s) {
        int n = s.length();

        int i = 0; 
        int j = 0;

        int[] freq = new int[26];

        int result = 0;

        while (j < n) {
            freq[s.charAt(j) - 'a']++;

            while (freq[s.charAt(j) - 'a'] > 2) {
                freq[s.charAt(i) - 'a']--;
                i++;
            }

            result = Math.max(result, j - i + 1);

            j++;
        }

        return result;
    }
}
