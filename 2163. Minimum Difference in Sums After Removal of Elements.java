class Solution {
    public long minimumDifference(int[] nums) {
        int N = nums.length;
        int n = N / 3;
        long[] leftMin = new long[N];
        long[] rightMax = new long[N];
        long leftSum = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 2 * n; i++) {
            maxHeap.add(nums[i]);
            leftSum += nums[i];
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.poll();
            }
            leftMin[i] = leftSum;
        }
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long rightSum = 0;
        for (int i = N - 1; i >= n; i--) {
            minHeap.add(nums[i]);
            rightSum += nums[i];
            if (minHeap.size() > n) {
                rightSum -= minHeap.poll();
            }
            rightMax[i] = rightSum;
        }
        long result = Long.MAX_VALUE;
        for (int i = n - 1; i <= 2 * n - 1; i++) {
            result = Math.min(result, leftMin[i] - rightMax[i + 1]);
        }
        return result;
    }
}
