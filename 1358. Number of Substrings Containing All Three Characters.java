class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int l = 0, r = 0;
        int[] cntThree = { 0, 0, 0 };
        int result = 0;
        while (r < n) {
            cntThree[s.charAt(r) - 'a']++;
            while (cntThree[0] > 0 && cntThree[1] > 0 && cntThree[2] > 0) {
                result += (n - r);
                cntThree[s.charAt(l) - 'a']--;
                l++;
            }
            r++;
        }
        return result;
    }
}
