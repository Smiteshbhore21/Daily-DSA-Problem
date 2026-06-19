class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitudes = 0;
        int maxAltitude = 0;

        for (int& num : gain) {
            altitudes += num;
            maxAltitude = max(maxAltitude, altitudes);
        }

        return maxAltitude;
    }
};
