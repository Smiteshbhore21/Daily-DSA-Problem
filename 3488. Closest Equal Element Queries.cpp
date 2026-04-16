class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int& q : queries) {
            int ele = nums[q];

            int sz = mp[ele].size();

            if (sz > 1) {
                int pos = lower_bound(begin(mp[ele]), end(mp[ele]), q) -
                          begin(mp[ele]);

                int res = INT_MAX;
                int rightNeigh = mp[ele][(pos + 1) % sz];
                int dist = abs(rightNeigh - q);
                int circDist = n - dist;
                res = min({res, dist, circDist});

                int leftNeigh = mp[ele][(pos - 1 + sz) % sz];
                dist = abs(leftNeigh - q);
                circDist = n - dist;
                res = min({res, dist, circDist});

                ans.push_back(res);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
