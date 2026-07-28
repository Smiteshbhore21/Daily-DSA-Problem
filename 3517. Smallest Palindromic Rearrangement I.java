class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();

        int[] charArray = new int[26];

        for (int i = 0; i < n / 2; i++) {
            char ch = s.charAt(i);

            charArray[ch - 'a']++;
        }

        StringBuilder result = new StringBuilder("");

        for (int i = 0; i < 26; i++) {
            while (charArray[i] != 0) {
                result.append((char) (i + 'a'));
                charArray[i]--;
            }
        }

        int firstHalfLength = result.length();

        if (n % 2 == 1) {
            result.append(s.charAt(n / 2));
        }

        for (int j = firstHalfLength - 1; j >= 0; j--) {
            result.append(result.charAt(j));
        }

        return result.toString();
    }
}
