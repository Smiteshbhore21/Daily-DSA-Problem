class Solution {
    public int maxDifference(String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
        }
        int maxOdd = Integer.MIN_VALUE, minEven = Integer.MAX_VALUE;
        for (int x : freq) {
            if (x > 0 && x % 2 == 0)
                minEven = Math.min(minEven, x);
            else
                maxOdd = Math.max(maxOdd, x);
        }
        return maxOdd - minEven;
    }
}
