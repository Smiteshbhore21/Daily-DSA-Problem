class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        map<int, int> diffArr;
        for (int& x : nums) {
            freq[x]++;
            pair<int, int> p = {max(x - k, 0), min(x + k, maxEle)};
            diffArr[x] += 0;
            diffArr[p.first]++;
            diffArr[p.second + 1]--;
        }
        int res = 1;
        map<int, int>::iterator it;
        int cumSum = 0;
        for (it = diffArr.begin(); it != diffArr.end(); ++it) {
            int target = it->first;
            it->second = (cumSum + it->second);
            int targetFreq = freq[target];
            int needConversion = it->second - targetFreq;
            int maxPosFreq = min(numOperations, needConversion);
            res = max(res, maxPosFreq + targetFreq);
            cumSum = it->second;
        }
        return res;
    }
};
