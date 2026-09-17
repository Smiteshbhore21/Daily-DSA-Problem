class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;

        int i = 0;
        int j = 0;

        int currSum = 0;
        int bestMinLen = Integer.MAX_VALUE;
        int result = Integer.MAX_VALUE;
        int[] minBestLenTillIdx = new int[n];
        Arrays.fill(minBestLenTillIdx, Integer.MAX_VALUE);

        while (i < n) {
            currSum += arr[i];

            while (j < i && currSum > target) {
                currSum -= arr[j];
                j++;
            }

            if (currSum == target) {
                int len = i - j + 1;

                if (j > 0 && minBestLenTillIdx[j - 1] != Integer.MAX_VALUE)
                    result = Math.min(result, len + minBestLenTillIdx[j - 1]);

                bestMinLen = Math.min(bestMinLen, len);
            }
            minBestLenTillIdx[i] = bestMinLen;
            i++;
        }

        return result != Integer.MAX_VALUE ? result : -1;

    }
}
