class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    break;
                }
            }
            if (j == n)
                ans++;
        }
        return ans;
    }
}
