class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start = 0, bitMask = 0, maxLen = 0, n = nums.size();
        for (int end = 0; end < n; end++) {
            while ((bitMask & nums[end]) != 0) {
                bitMask = bitMask ^ nums[start];
                start++;
            }
            bitMask = bitMask | nums[end];
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
