class Solution {
    public int maxSum(int[] nums) {
        int freq[] = new int[101];
        int maxNeg = Integer.MIN_VALUE;
        boolean zero = false;
        int sum = 0;
        for (int x : nums) {
            if (x >= 0 && freq[x] >= 1)
                continue;
            if (x >= 0) {
                if (x == 0)
                    zero = true;
                freq[x]++;
                sum += x;
            } else {
                maxNeg = Math.max(maxNeg, x);
            }
        }
        if (sum == 0 && !zero)
            return maxNeg;
        return sum;
    }
}
