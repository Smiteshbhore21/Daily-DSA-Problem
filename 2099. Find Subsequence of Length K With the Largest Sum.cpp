// O(n) -->
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(),
                    greater<int>());
        int kthLargest = temp[k - 1];
        int countKthLargest = count(begin(temp), begin(temp) + k, kthLargest);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > kthLargest) {
                ans.push_back(nums[i]);
            } else if (nums[i] == kthLargest && countKthLargest) {
                ans.push_back(nums[i]);
                countKthLargest--;
            } else {
                continue;
            }
            if (ans.size() == k)
                return ans;
        }
        return ans;
    }
};

// O(nlog(n)) -->
// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         vector<vector<int>> sortByInd;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             sortByInd.push_back({i, nums[i]});
//         }
//         sort(sortByInd.begin(), sortByInd.end(),
//              [](vector<int>& p1, vector<int>& p2) { return p1[1] > p2[1]; });
//         sort(sortByInd.begin(), sortByInd.begin() + k);
//         vector<int> ans(k);
//         for (int i = 0; i < k; i++) {
//             ans[i] = sortByInd[i][1];
//         }
//         return ans;
//     }
// };
