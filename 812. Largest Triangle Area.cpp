class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double x1 = points[i][0];
                    double y1 = points[i][1];

                    double x2 = points[j][0];
                    double y2 = points[j][1];

                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    // double a = sqrt((x2 - x1) << 1 + (y2 - y1) << 1);
                    // double a = hypot((x2 - x1), (y2 - y1));
                    // double b = hypot((x2 - x3), (y2 - y3));
                    // double c = hypot((x3 - x1), (y3 - y1));

                    // double s = (a + b + c) * 0.5;
                    // herons
                    // double area = sqrt(s * (s - a) * (s - b) * (s - c));
                    // shoelace
                    double area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) +
                                            x3 * (y1 - y2));
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
};
