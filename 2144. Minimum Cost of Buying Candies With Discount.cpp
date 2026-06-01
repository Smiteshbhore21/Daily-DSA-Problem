class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost), greater<int>());
        int n = cost.size();
        int result = 0;
        for (int i = 0; i < n; i += 3) {
            result += (cost[i] + (i + 1 < n ? cost[i + 1] : 0));
        }
        return result;
    }
};
