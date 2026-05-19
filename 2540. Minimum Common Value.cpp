class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0, j = 0;
        int result = INT_MAX;
        while (i < n1 && j < n2) {

            if (nums1[i] == nums2[j])
                result = min(result, nums1[i]);

            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
