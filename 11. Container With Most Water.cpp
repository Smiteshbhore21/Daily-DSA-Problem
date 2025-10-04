class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmt = 0, n = height.size();
        for (int i = 0, j = n - 1; i < j;) {
            int minSide = min(height[i], height[j]);
            maxAmt = max(minSide * (j - i), maxAmt);
            if (height[i] == minSide)
                i++;
            else
                j--;
        }
        return maxAmt;
    }
};
