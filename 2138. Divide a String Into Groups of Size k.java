class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int groups = (n + k - 1) / k;
        String[] ans = new String[groups];
        int idx = 0;
        for (int i = 0; i < n;) {
            StringBuilder temp = new StringBuilder();
            while (temp.length() != k && i < n) {
                temp.append(s.charAt(i++));
            }
            while (i >= n && temp.length() != k) {
                temp.append(fill);
            }
            ans[idx++] = temp.toString();
        }
        return ans;
    }
}
