class Solution {
    public long gcdSum(int[] nums) {
        int n = nums.length;

        int maxEle = nums[0];
        int largestGCD = Integer.MIN_VALUE;
        int smallestGCD = Integer.MAX_VALUE;
        ArrayList<Integer> prefixGcd = new ArrayList<>();

        for (int num : nums) {
            maxEle = Math.max(num, maxEle);
            int gcd = gcd(maxEle, num);
            prefixGcd.add(gcd);
        }

        prefixGcd.sort(Comparator.naturalOrder());

        long result = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            result += (gcd(prefixGcd.get(i), prefixGcd.get(j)));
        }

        return result;
    }

    public int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
