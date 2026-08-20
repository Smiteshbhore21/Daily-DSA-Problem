class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;

        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        arr1.add(nums[0]);
        arr2.add(nums[1]);

        for (int i = 2; i < n; i++) {
            if (arr1.getLast() > arr2.getLast()) {
                arr1.add(nums[i]);
            } else {
                arr2.add(nums[i]);
            }
        }

        int i = 0;
        for (Integer num : arr1) {
            nums[i] = num;
            i++;
        }
        
        for (Integer num : arr2) {
            nums[i] = num;
            i++;
        }

        return nums;
    }
}
