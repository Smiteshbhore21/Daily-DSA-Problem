class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), x1 = 0, x2 = 0;
        if (n2 % 2 != 0)
            for (int x : nums1)
                x1 ^= x;

        if (n1 % 2 != 0)
            for (int x : nums2)
                x2 ^= x;

        return x1 ^ x2;
    }
};
