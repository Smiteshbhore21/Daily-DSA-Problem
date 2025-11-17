class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int lastOnePos = -k - 1;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1 && (i - lastOnePos - 1) >= k){
                    lastOnePos = i;
            }else if (nums[i] == 1){
                return false;
            }
        }
        return true;
    }
}
