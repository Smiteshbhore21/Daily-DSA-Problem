class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), ind1 = 0, ind2 = 0;
        vector<vector<int>> ans;

        while (ind1 < n1 && ind2 < n2) {
            if (nums1[ind1][0] > nums2[ind2][0])
                ans.push_back(nums2[ind2++]);
            else if (nums1[ind1][0] < nums2[ind2][0])
                ans.push_back(nums1[ind1++]);
            else

                ans.push_back(
                    {nums1[ind1][0], nums1[ind1++][1] + nums2[ind2++][1]});
        }
        while (ind1 < n1)
            ans.push_back(nums1[ind1++]);
        while (ind2 < n2)
            ans.push_back(nums2[ind2++]);
        return ans;

        // int n1 = nums1.size(), n2 = nums2.size();
        // vector<vector<int>> ans;
        // unordered_map<int, int> m1, m2;
        // for (int i = 0; i < n1; i++)
        //     m1[nums1[i][0]] = i;
        // for (int i = 0; i < n2; i++)
        //     m2[nums2[i][0]] = i;
        // for (int i = 1; i < 1001; i++) {
        //     if (m1.find(i) != m1.end()) {
        //         if (m2.find(i) != m2.end()) {
        //             ans.push_back({i, nums1[m1[i]][1] + nums2[m2[i]][1]});
        //         } else {
        //             ans.push_back(nums1[m1[i]]);
        //         }
        //     } else if (m2.find(i) != m2.end()) {
        //         if (m1.find(i) != m1.end()) {
        //             ans.push_back({i, nums1[m1[i]][1] + nums2[m2[i]][1]});
        //         } else {
        //             ans.push_back(nums2[m2[i]]);
        //         }
        //     }
        // }
        // return ans;
    }
};
