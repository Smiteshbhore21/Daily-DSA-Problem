int MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> rightFreq, leftFreq;
        for (const int& num : nums) {
            rightFreq[num]++;
        }
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            int numj = nums[i] * 2;
            if (numj == 0 && rightFreq[numj] > 0 && leftFreq[numj] > 0) {
                result =
                    (result + 1ll* leftFreq[numj] * (rightFreq[numj] - 1)) % MOD;
            } else if (rightFreq[numj] > 0 && leftFreq[numj] > 0) {
                result = (result + leftFreq[numj] * rightFreq[numj]) % MOD;
            }
            leftFreq[nums[i]]++;
            rightFreq[nums[i]]--;
        }
        return result;
    }
};
