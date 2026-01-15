class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        int largestConsecutiveHBar = 1;
        int lengthSubarray = 1;
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i - 1] == hBars[i] - 1) {
                lengthSubarray++;
                largestConsecutiveHBar = Math.max(largestConsecutiveHBar, lengthSubarray);
            } else {
                lengthSubarray = 1;
            }
        }
        lengthSubarray = 1;
        int largestConsecutiveVBar = 1;
        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i - 1] == vBars[i] - 1) {
                lengthSubarray++;
                largestConsecutiveVBar = Math.max(largestConsecutiveVBar, lengthSubarray);
            } else {
                lengthSubarray = 1;
            }
        }
        int side = Math.min((largestConsecutiveHBar + 1), (largestConsecutiveVBar + 1));
        return binaryExpo(side, 2);
    }

    public int binaryExpo(int a, int b) {
        if (b == 0)
            return 1;
        int half = binaryExpo(a, b / 2);
        if (b % 2 == 1) {
            return half * half * a;
        }
        return half * half;
    }
}
