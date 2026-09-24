class Solution {
    public int smallestIndex(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (digitSum(num) == i)
                return i;
        }

        return -1;
    }

    public int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum = sum + (num % 10);
            num /= 10;
        }
        return sum;
    }
}
