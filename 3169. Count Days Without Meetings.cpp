class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int ans = 0, lastDate = 0;
        for (vector<int>& x : meetings) {
            if (lastDate < x[0])
                ans += x[0] - lastDate - 1;

            lastDate = max(lastDate, x[1]);
        }

        ans += days - lastDate;

        return ans;
    }
};

// TLE ---->
// class Solution {
// public:
//     vector<bool> markMeetings;
//     int countDays(int days, vector<vector<int>>& meetings) {
//         markMeetings.assign(days, false);
//         int ans = 0;
//         for (auto& x : meetings) {
//             markMeets(x[0], x[1]);
//         }
//         for (int i = 0; i < markMeetings.size(); i++)
//             if (!markMeetings[i])
//                 ans++;
//         return ans;
//     }
//     void markMeets(int start, int end) {
//         for (int i = start; i <= end; i++) {
//             markMeetings[i - 1] = true;
//         }
//     }
// };
