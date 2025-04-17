class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, vector<int>> indMap;
        for (int i = 0; i < n; i++) {
            indMap[nums[i]].push_back(i);
        }

        unordered_set<int> div;
        for (int f = 1; f * f <= k; f++) {
            if (k % f == 0) {
                div.insert(f);
                div.insert(k / f);
            }
        }

        for (auto& [_, indices] : indMap) {
            unordered_map<int, int> factorsMap;
            for (int& i : indices) {
                int GCD = gcd(i, k); // T.C : log(k)
                int j = k / GCD;
                ans += factorsMap[j];

                for (const int& f : div) {
                    if (i % f == 0)
                        factorsMap[f]++;
                }
            }
        }

        return ans;
    }
};
