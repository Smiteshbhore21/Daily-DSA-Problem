class Solution {
    public int minimumRecolors(String blocks, int k) {
        int n = blocks.length(), wCount = 0;
        //first window
        for (int i = 0; i < k; i++)
            if (blocks.charAt(i) == 'W')
                wCount++;
        int minSwap = wCount;
        //next window
        for (int i = 1; i <= n - k; i++) {
            if (blocks.charAt(i-1) == 'W')
                wCount--;
            if (blocks.charAt(i+k-1) == 'W')
                wCount++;
            minSwap = Math.min(wCount, minSwap);
        }
        return minSwap;
    }
}
