using Node = pair<long long, vector<int>>;

class Solution {
public:
    int n;
    vector<int> nextIdx;

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end);
        }

        int k = 4;

        vector<vector<Node>> dp(n + 1, vector<Node>(k + 1, {0, {}}));

        for (int i = n - 1; i >= 0; i--) {

            for (int cnt = 1; cnt <= k; cnt++) {

                Node skip = dp[i + 1][cnt];

                int weight = intervals[i][2];
                int idx = intervals[i][3];

                int j = nextIdx[i];

                Node take = dp[j][cnt - 1];

                take.first += weight;
                take.second.push_back(idx);

                sort(take.second.begin(), take.second.end());

                Node result;

                if (skip.first > take.first) {
                    result = skip;
                } else if (skip.first < take.first) {
                    result = take;
                } else {
                    result = (skip.second < take.second) ? skip : take;
                }

                dp[i][cnt] = result;
            }
        }

        return dp[0][k].second;
    }

    int findNext(vector<vector<int>>& intervals, int r) {

        int lo = 0;
        int hi = n - 1;
        int result = n;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return result;
    }
};
