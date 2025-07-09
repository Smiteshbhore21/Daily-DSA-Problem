class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        freeTime.push_back(startTime[0] - 0);
        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[n - 1]);
        n++;
        int i = 0, j = 0, maxSum = 0, currSum = 0;
        while (j < n) {
            currSum += freeTime[j];
            if (j - i + 1 > k + 1) {
                currSum -= freeTime[i];
                i++;
            }
            maxSum = max(maxSum, currSum);
            j++;
        }
        return maxSum;
    }
};

// class Solution {
// public:
//     int maxFreeTime(int eventTime, int k, vector<int>& startTime,
//                     vector<int>& endTime) {
//         int n = startTime.size();
//         vector<int> freeTime;
//         if (startTime[0] - 0 != 0)
//             freeTime.push_back(startTime[0] - 0);
//         for (int i = 1; i < n; i++) {
//             int calcFreeTime = startTime[i] - endTime[i - 1];
//             freeTime.push_back(calcFreeTime);
//         }
//         if (eventTime - endTime[n - 1] != 0)
//             freeTime.push_back(eventTime - endTime[n - 1]);
//         int window = k + 1;
//         n = freeTime.size();
//         int result = 0;
//         int start = 0, end = 0;
//         int sum = 0;
//         while (end != n) {
//             sum += freeTime[end];
//             while (end - start + 1 > window) {
//                 sum -= freeTime[start++];
//             }
//             result = max(result, sum);
//             end++;
//         }
//         return result;
//     }
// };
