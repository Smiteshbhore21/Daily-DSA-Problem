class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int[] freq = new int[101];

        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;

        for (int val : nums) {
            minVal = Math.min(val, minVal);
            maxVal = Math.max(val, maxVal);
            freq[val]++;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = minVal; i <= maxVal; i++) {
            if (freq[i] == 0)
                result.add(i);
        }

        return result;
    }
}
