class Solution {
    public int maxDistance(String s, int k) {
        int n = s.length();
        int east = 0, west = 0, north = 0, south = 0;
        int maxMD = 0;
        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
            }
            int curMD = Math.abs(east - west) + Math.abs(north - south);
            int steps = i + 1;
            int wasted = steps - curMD;
            int extra = 0;
            if (wasted != 0) {
                extra = Math.min(k * 2, wasted);
            }
            maxMD = Math.max(maxMD, curMD + extra);
        }
        return maxMD;
    }
}
