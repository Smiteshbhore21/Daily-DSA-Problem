class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans++;
    }
};

// O(n^2 * log(n)) -->
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size(), ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0)
//                 continue;
//             for (int j = i + 1; j < n; j++) {
//                 int start = j + 1, end = n - 1;
//                 int k = -1;
//                 while (start <= end) {
//                     int mid = start + (end - start) / 2;
//                     if (nums[mid] < nums[i] + nums[j]) {
//                         k = mid;
//                         start = mid + 1;
//                     } else {
//                         end = mid - 1;
//                     }
//                 }
//                 if (k != -1)
//                     ans += (k - j);
//             }
//         }
//         return ans;
//     }
// };

// O(n^3) -->
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size(), ans = 0;
//         for (int i = 0; i < n - 2; i++) {
//             for (int j = i + 1; j < n - 1; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] + nums[j] > nums[k]) {
//                         ans++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
