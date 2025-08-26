class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestDiag2 = -1;   
        int bestArea  = 0;    

        for (auto &d : dimensions) {
            int l = d[0];
            int w = d[1];
            int diag2 = l*l + w*w;
            int area  = l * w;

            if (diag2 > bestDiag2) {
                bestDiag2 = diag2;
                bestArea  = area;          
            } else if (diag2 == bestDiag2 && area > bestArea) {
                bestArea = area;          
            }
        }

        return bestArea; 
    }
};
