class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int count = 1;
        int n = prices.size();
        long long result = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1)
                count++;
            else {
                count = 1;
            }
            result += count;
        }
        return result;
    }
};
