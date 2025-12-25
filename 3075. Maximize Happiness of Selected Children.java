class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long result = 0;
        int pickedChilds = 0;
        int n = happiness.length;
        for (int i = n - 1; i >= 0; i--) {
            if (k == 0) {
                break;
            }
            result += Math.max(0, happiness[i] - pickedChilds);
            k--;
            pickedChilds++;
        }
        return result;
    }
}
