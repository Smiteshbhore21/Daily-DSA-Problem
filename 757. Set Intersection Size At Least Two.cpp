class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int count = 2;
        sort(intervals.begin(), intervals.end(),
             [&](vector<int>& a, vector<int>& b) {
                 if (a[1] == b[1]) {
                     return a[0] > b[0];
                 }
                 return a[1] < b[1];
             });
        vector<int> maxInterval(2, 0);
        maxInterval[0] = intervals[0][1] - 1;
        maxInterval[1] = intervals[0][1];
        int n = intervals.size();

        for (int i = 1; i < n; i++) {
            if (maxInterval[1] < intervals[i][0]) {
                count += 2;
                maxInterval[0] = intervals[i][1] - 1;
                maxInterval[1] = intervals[i][1];
            } else if (maxInterval[0] < intervals[i][0]) {
                count += 1;
                maxInterval[0] = maxInterval[1];
                maxInterval[1] = intervals[i][1];
            }
        }
        return count;
    }
};
