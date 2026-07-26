class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;

        int last3 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int fisrt2Last1 = nums[0] * nums[1] * nums[n - 1];

        return (last3 > fisrt2Last1) ? last3 : fisrt2Last1;
    }
}
