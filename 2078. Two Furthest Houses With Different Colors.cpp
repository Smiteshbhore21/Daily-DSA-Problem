class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;
        for (int i = n - 1; i > 0; i--) {
            if (colors[0] != colors[i]) {
                result = abs(i - 0);
                break;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (colors[n - 1] != colors[i]) {
                result = max(result, abs(i - (n - 1)));
                break;
            }
        }

        return result;
    }
};
