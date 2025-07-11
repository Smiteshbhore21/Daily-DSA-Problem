class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            occupiedRooms, freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push({0, i});
        }
        vector<int> freqRoom(n, 0);

        for (int i = 0; i < meetings.size(); i++) {
            while (!occupiedRooms.empty() &&
                   occupiedRooms.top().first <= meetings[i][0]) {
                pair<long long, int> curr = occupiedRooms.top();
                occupiedRooms.pop();
                curr.first = 0;
                freeRooms.push(curr);
            }
            if (!freeRooms.empty()) {
                pair<long long, int> curr = freeRooms.top();
                freeRooms.pop();
                freqRoom[curr.second]++;
                curr.first = meetings[i][1];
                occupiedRooms.push(curr);
            } else {
                pair<long long, int> curr = occupiedRooms.top();
                occupiedRooms.pop();
                freqRoom[curr.second]++;
                curr.first += 1ll * (meetings[i][1] - meetings[i][0]);
                occupiedRooms.push(curr);
            }
        }

        int maxMeetings = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            if (freqRoom[i] > maxMeetings) {
                maxMeetings = freqRoom[i];
                idx = i;
            }
        }
        return idx;
    }
};
