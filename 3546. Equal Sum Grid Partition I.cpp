class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalRowSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalRowSum += grid[i][j];
            }
        }
        
        if (totalRowSum % 2 != 0) return false;

        long long totalColSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalColSum += grid[j][i];
            }
        }


        long long currRowSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                currRowSum += grid[i][j];
            }
            if (totalRowSum - currRowSum == currRowSum)
                return true;
        }

        long long currColSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                currColSum += grid[j][i];
            }
            if (totalColSum - currColSum == currColSum)
                return true;
        }

        return false;
    }
};
