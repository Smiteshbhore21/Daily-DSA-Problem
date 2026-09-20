class Solution {
    public int reverseDegree(String s) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int ch = 'z' - s.charAt(i) + 1;
            result += (ch * (i + 1));
        }

        return result;
    }
}
