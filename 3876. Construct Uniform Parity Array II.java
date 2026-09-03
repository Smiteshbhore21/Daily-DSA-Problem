class Solution {
    public boolean uniformArray(int[] nums1) {
        int smallestNum = Arrays.stream(nums1).min().getAsInt();

        if (smallestNum % 2 == 1)
            return true;

        for (int num : nums1) {
            if (num % 2 == 1)
                return false;
        }

        return true;

    }
}
