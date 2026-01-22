class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        vector<int> prev = nums;

        while (!isNonDecreasing(prev)) {
            pair<int, int> p = minSumPair(prev);
            vector<int> temp;
            for (int j = 0; j < prev.size(); j++) {
                if (j == p.first) {
                    temp.push_back(prev[p.first] + prev[p.second]);
                    j++;
                } else {
                    temp.push_back(prev[j]);
                }
            }
            prev = temp;
            ops++;
        }

        return ops;
    }

    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    pair<int, int> minSumPair(vector<int>& nums) {
        pair<int, int> p = {-1, -1};
        int minSum = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i - 1] + nums[i]) < minSum) {
                p.first = i - 1;
                p.second = i;
                minSum = nums[i - 1] + nums[i];
            }
        }
        return p;
    }
};
