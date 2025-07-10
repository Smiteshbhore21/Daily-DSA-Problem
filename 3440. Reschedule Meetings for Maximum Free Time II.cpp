class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        freeTime.push_back(startTime[0] - 0);
        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[n - 1]);
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = freeTime[0];
        suffix[n] = freeTime[n];
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = max(prefix[i - 1], freeTime[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], freeTime[i]);
        }
        int ans = prefix[n];
        for (int i = 0; i < n; i++) {
            int eventDuration = endTime[i] - startTime[i];
            int bestBefore = (i - 1 >= 0 ? prefix[i - 1] : 0);
            int bestAfter = (i + 2 <= n ? suffix[i + 2] : 0);
            int maxGap = max(bestBefore, bestAfter);
            if (maxGap >= eventDuration) {
                ans = max(ans, freeTime[i] + freeTime[i + 1] + eventDuration);
            } else {
                ans = max(ans, freeTime[i] + freeTime[i + 1]);
            }
        }
        return ans;
    }
};
