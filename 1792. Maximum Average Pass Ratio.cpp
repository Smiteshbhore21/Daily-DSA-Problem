using P = pair<double, int>;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; // max-heap
        for (int i = 0; i < n; i++) {
            double curr_pr = (double)classes[i][0] / classes[i][1];
            double new_pr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = new_pr - curr_pr;
            pq.push({delta, i});
        }

        while (extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            double detla = curr.first;
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;
            double curr_pr = (double)classes[idx][0] / classes[idx][1];
            double new_pr =
                (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            double delta = new_pr - curr_pr;
            pq.push({delta, idx});
        }

        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += (double)classes[i][0] / classes[i][1];
        }

        return result / n;
    }
};

// MLE -->
// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         int n = classes.size();

//         vector<double> PR(n);
//         for (int i = 0; i < n; i++) {
//             double ratio = (double)classes[i][0] / classes[i][1];
//             PR[i] = ratio;
//         }

//         while (extraStudents--) {
//             vector<double> updatePR(n);
//             for (int i = 0; i < n; i++) {
//                 double newRatio =
//                     (double)(classes[i][0] + 1) / (classes[i][1] + 1);
//                 updatePR[i] = newRatio;
//             }

//             int bestClassIdx = 0;
//             double bestDelta = 0.0;

//             for (int i = 0; i < n; i++) {
//                 double delta = updatePR[i] - PR[i];
//                 if (bestDelta < delta) {
//                     bestClassIdx = i;
//                     bestDelta = delta;
//                 }
//             }

//             PR[bestClassIdx] = updatePR[bestClassIdx];
//             classes[bestClassIdx][0]++;
//             classes[bestClassIdx][1]++;
//         }
//         double result = 0.0;
//         for (int i = 0; i < n; i++) {
//             result += PR[i];
//         }

//         return result/n;
//     }
// };
