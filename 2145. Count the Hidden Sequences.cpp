class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0, minVal = 0, maxVal = 0;
        for (const int& d : differences) {
            curr = curr + d;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
            if ((upper - maxVal) - (lower - minVal) + 1 <= 0)
                return 0;
        }
        return (upper - maxVal) - (lower - minVal) + 1;
    }
};
