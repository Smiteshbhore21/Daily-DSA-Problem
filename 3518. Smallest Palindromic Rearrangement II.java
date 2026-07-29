class Solution {

    public long nCr(int n, int r, long k) {
        r = Math.min(r, n - r);

        long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= k)
                return k;
        }

        return result;
    }

    public String smallestPalindrome(String s, int k) {
        int n = s.length();

        char mid = ' ';
        int[] count = new int[26];

        if (n % 2 == 1) {
            mid = s.charAt(n / 2);
        }

        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && n / 2 == i)
                continue;

            char ch = s.charAt(i);
            count[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        StringBuilder halfResult = new StringBuilder("");
        int half = n / 2;

        for (int i = 0; i < half; i++) {

            boolean placedChar = false;
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    count[j]--;

                    long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for (int c = 0; c < 26; c++) {
                        if (count[c] > 0) {
                            ways *= nCr(letters, count[c], k);
                            letters -= count[c];
                        }

                        if (ways >= k)
                            break;
                    }

                    if (ways >= k) {
                        halfResult.append((char) (j + 'a'));
                        placedChar = true;
                        break;
                    }

                    k -= ways;
                    count[j]++;
                }
            }

            if (!placedChar) {
                return "";
            }

        }

        String firstHalf = halfResult.toString();
        String rev = new StringBuilder(firstHalf).reverse().toString();

        if (mid != ' ') {
            halfResult.append(mid);
        }

        return halfResult.toString() + rev;
    }
}
