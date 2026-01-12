class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length;
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            int dx = Math.abs(x2-x1);
            int dy = Math.abs(y2-y1);

            result += (Math.min(dx, dy) + Math.abs(dy - dx));
        }
        return result;
    }
}

// O(N*M) --> 
// class Solution {
//     public int minTimeToVisitAllPoints(int[][] points) {
//         int n = points.length;
//         int x = points[0][0], y = points[0][1];
//         int result = 0;
//         for (int i = 1; i < n; i++) {
//             while (x != points[i][0] || y != points[i][1]) {
//                 if (x == points[i][0]) {
//                     result += ((y > points[i][1]) ? y - points[i][1] : points[i][1] - y);
//                     x = points[i][0];
//                     y = points[i][1];
//                     break;
//                 } else if (x < points[i][0]) {
//                     x++;
//                 } else if (x > points[i][0]) {
//                     x--;
//                 }
//                 if (y == points[i][1]) {
//                     result += Math.abs(x - points[i][0]) + 1;
//                     x = points[i][0];
//                     y = points[i][1];
//                     break;
//                 } else if (y < points[i][1]) {
//                     y++;
//                 } else if (y > points[i][1]) {
//                     y--;
//                 }
//                 result++;
//             }
//         }
//         return result;
//     }
// }
