class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();

        int l = 0;
        int oneCnt = 0;

        String result = "";

        for (int r = 0; r < n; r++) {

            if (s.charAt(r) == '1') {
                oneCnt++;
            }

            while (oneCnt > k) {
                if (s.charAt(l) == '1') {
                    oneCnt--;
                }
                l++;
            }

            if (oneCnt == k) {
                while (s.charAt(l) == '0') {
                    l++;
                }

                String current = s.substring(l, r + 1);
                if (result.isEmpty()
                        || current.length() < result.length()
                        || (current.length() == result.length()
                                && current.compareTo(result) < 0)) {

                    result = current;
                }
            }
        }

        return result;
    }
}
