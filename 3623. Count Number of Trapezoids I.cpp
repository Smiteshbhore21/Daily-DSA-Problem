int MOD = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for (auto& point : points) {
            mp[point[1]]++;
        }

        long long edgesSum = 0;
        for (auto& [key, val] : mp) {
            long long edges = (val * 1ll * (val - 1)) / 2;

            ans = (ans + edges * edgesSum) % MOD;
            edgesSum += edges;
        }
        return ans;
    }
};
