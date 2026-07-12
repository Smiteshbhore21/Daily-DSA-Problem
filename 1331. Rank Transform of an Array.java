class Solution {
    public int[] arrayRankTransform(int[] arr) {
        TreeMap<Integer, Integer> nums = new TreeMap<>();

        for (int num : arr) {
            nums.put(num, 0);
        }

        int rank = 1;
        for (TreeMap.Entry<Integer, Integer> entry : nums.entrySet()) {
            nums.replace(entry.getKey(), rank++);
        }

        int n = arr.length;
        for (int i = 0; i < n; i++) {
            arr[i] = nums.get(arr[i]);
        }

        return arr;
    }
}
