class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        size_t n = fruits.size();
        vector<int> prefixSum(n), positions(n);
        positions[0] = fruits[0][0];
        prefixSum[0] = fruits[0][1];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + fruits[i][1];
            positions[i] = fruits[i][0];
        }
        int d = 0;
        int maxFruits = 0;
        while (d <= (k / 2)) {
            // case 1 left to right
            int i = startPos - d;
            int j = startPos + k - (2 * d);
            int left = lower_bound(positions.begin(), positions.end(), i) -
                       positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) -
                        positions.begin() - 1;

            if (left <= right) {
                int total =
                    prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // case 2 right to left
            i = startPos - (k - 2 * d);
            j = startPos + d;
            left = lower_bound(positions.begin(), positions.end(), i) -
                   positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) -
                    positions.begin() - 1;

            if (left <= right) {
                int total =
                    prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            d++;
        }
        return maxFruits;
    }
};
