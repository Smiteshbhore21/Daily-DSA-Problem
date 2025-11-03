class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int minTime = 0;
        int i = 0, j = 1;
        while (j < n) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] <= neededTime[j]) {
                    minTime += neededTime[i];
                    i = j;
                    j++;
                } else {
                    minTime += neededTime[j];
                    j++;
                }
            } else {
                i = j;
                j++;
            }
        }
        return minTime;
    }
};

// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         int minTime = 0;
//         for (int i = 1; i < n;) {
//             priority_queue<int, vector<int>, greater<int>> pq;
//             pq.push(neededTime[i - 1]);
//             while (i < n && colors[i] == colors[i - 1]) {
//                 pq.push(neededTime[i]);
//                 i++;
//             }
//             if (pq.size() == 1)
//                 i++;
//             while (pq.size() != 1) {
//                 minTime += pq.top();
//                 pq.pop();
//             }
//         }
//         return minTime;
//     }
// };
