class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> candidates;
        for (int i = 0; i < n - 1; i++) {
            candidates.push_back(weights[i] + weights[i + 1]);
        }
        sort(candidates.begin(), candidates.end());
        long long min_sum = 0, max_sum = 0;
        for (int i = 0; i < k - 1; i++) {
            min_sum += candidates[i];
            max_sum += candidates[n - 2 - i];
        }
        return max_sum - min_sum;
    }
};
