class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> divisorFreq(maxVal + 1, 0);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    divisorFreq[j]++;

                    if (num / j != j)
                        divisorFreq[num / j]++;
                }
            }
        }

        vector<long long> pairsWithGCD(maxVal + 1, 0);

        for (int g = maxVal; g > 0; g--) {
            long long cnt = divisorFreq[g];
            long long cntPairs = cnt * (cnt - 1) / 2;

            pairsWithGCD[g] = cntPairs;

            for (int mult = 2 * g; mult <= maxVal; mult += g) {
                pairsWithGCD[g] -= pairsWithGCD[mult];
            }
        }

        vector<long long> prefixCntGCD(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            prefixCntGCD[g] = prefixCntGCD[g - 1] + pairsWithGCD[g];
        }

        vector<int> result;

        for (long long idx : queries) {
            int l = 1;
            int r = maxVal;
            int temp = 0;

            while (l <= r) {
                int mid_gcd = l + (r - l) / 2;

                if (prefixCntGCD[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                } else {
                    l = mid_gcd + 1;
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};
