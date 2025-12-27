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

// (O(m * n) + O(n * log(n)) -->
// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());
//         vector<int> freqRoom(n, 0);
//         vector<long long> availableTime(n, 0);
//         int m = meetings.size();
//         for (vector<int>& meet : meetings) {
//             int start = meet[0];
//             int end = meet[1];
//             int duration = end - start;
//             bool found = false;
//             long long earlyEndRoomTime = LLONG_MAX;
//             int earlyEndRoom = 0;
//             for (int room = 0; room < n; room++) {
//                 if (availableTime[room] <= start) {
//                     availableTime[room] = end;
//                     freqRoom[room]++;
//                     found = true;
//                     break;
//                 }
//                 if (earlyEndRoomTime > availableTime[room]) {
//                     earlyEndRoomTime = availableTime[room];
//                     earlyEndRoom = room;
//                 }
//             }
//             if (!found) {
//                 availableTime[earlyEndRoom] += duration;
//                 freqRoom[earlyEndRoom]++;
//             }
//         }
//         int resultRoom = -1;
//         int maxUse = 0;
//         for(int room = 0; room < n; room++){
//             if(freqRoom[room] > maxUse){
//                 maxUse = freqRoom[room];
//                 resultRoom = room;
//             }
//         }
//         return resultRoom;
//     }
// };
