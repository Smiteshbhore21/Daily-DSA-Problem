class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m = nums.size();
        for (int i = 2; i < m; i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2])
                return nums[i];
        }
        return nums[0];
    }
};

// Space --> O(n+1)
// Time --> O(n)
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int& num : nums) {
//             freq[num]++;
//             if (freq[num] > 1)
//                 return num;
//         }
//         return 0;
//     }
// };
