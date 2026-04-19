// O(N + M) -->
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int result = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                result = max(result, j - i);
                j++;
            } else {
                i++;
                if (i > j)
                    j = i;
            }
        }
        return result;
    }
};

// O(N * (log(M))) -->
// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int result = 0;
//         for (int i = 0; i < n; i++) {
//             int num = nums1[i];
//             int pos = binary_search(nums2, num);
//             if (pos != -1 && i <= pos) {
//                 result = max(result, pos - i);
//             }
//         }
//         return result;
//     }
//     int binary_search(vector<int>& nums2, int num) {
//         int n = nums2.size();
//         int l = 0;
//         int r = n - 1;
//         int pos = -1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (nums2[mid] < num) {
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//                 pos = mid;
//             }
//         }
//         return pos;
//     }
// };
