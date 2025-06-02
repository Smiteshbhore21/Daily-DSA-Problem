class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), candy = n;
        for (int i = 1; i < n;) {
            int peak = 0, dip = 0;
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            while (ratings[i] > ratings[i - 1]) {
                peak++;
                candy += peak;
                i++;
                if (i == n)
                    return candy;
            }
            while (i < n  && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += dip;
                i++;
            }
            candy -= min(peak, dip);
        }
        return candy;
    }
};


// O(n) --> 
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> ans(n, 1);
//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i - 1]) {
//                 ans[i] =  max(ans[i - 1] + 1, ans[i]);
//             }
//         }
//         for (int i = n - 2; i >= 0; i--) {
//             if (ratings[i] > ratings[i + 1]) {
//                 ans[i] = max(ans[i + 1] + 1, ans[i]);
//             }
//         }
//         return accumulate(ans.begin(), ans.end(), 0);
//     }
// };
