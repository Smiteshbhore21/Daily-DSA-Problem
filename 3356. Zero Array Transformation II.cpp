class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, pos = 0;
        vector<int> diff(n + 1);
        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) {
                if (pos == queries.size())
                    return -1;
                int start = queries[pos][0], end = queries[pos][1],
                    val = queries[pos][2];
                pos++;
                if (end < i)
                    continue;
                diff[max(start, i)] += val;
                diff[end + 1] -= val;
            }
            sum += diff[i];
        }
        return pos;
    }

    //TLE-->
    // int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //     int ans = 0, n = nums.size(), zeroCount = 0;
    //     for (int i = 0; i < n; i++)
    //         if (nums[i] == 0)
    //             zeroCount++;

    //     for (int i = 0; i < queries.size(); i++) {
    //         int start = queries[i][0], end = queries[i][1], val =
    //         queries[i][2]; for (start; start <= end; start++) {
    //             if (nums[start] >= val) {
    //                 nums[start] -= val;
    //                 zeroCount = nums[start] == 0 ? zeroCount + 1 : zeroCount;
    //             } else if (nums[start] < val && nums[start] != 0){
    //                 nums[start]=0;
    //                 zeroCount++;
    //             }
    //         }
    //         ans++;
    //         if (zeroCount == n)
    //             return ans;
    //     }
    //     return (zeroCount == n) ? ans : -1;
    // }
};
