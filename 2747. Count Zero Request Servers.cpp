class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = logs.size();

        sort(begin(logs), end(logs),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();
        vector<pair<int, int>> timeIndex;
        for (int i = 0; i < q; i++) {
            timeIndex.push_back({queries[i], i});
        }

        sort(begin(timeIndex), end(timeIndex));

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        vector<int> result(q);
        for (auto& [time, idx] : timeIndex) {
            int start = time - x;
            int end = time;

            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            while (i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;

                if (mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx] = n - mp.size();
        }

        return result;
    }
};
