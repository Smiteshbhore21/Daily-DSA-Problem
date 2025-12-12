class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {

        sort(events.begin(), events.end(),
             [](vector<string>& eventA, vector<string>& eventB) {
                 int timeA = stoi(eventA[1]);
                 int timeB = stoi(eventB[1]);
                 if (timeA == timeB)
                     return (eventA[0][0] == 'O');
                 return timeA < timeB;
             });

        vector<int> offlineTime(numberOfUsers, 0),
            mentionCount(numberOfUsers, 0);

        for (vector<string>& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);
            if (type[0] == 'M') {
                vector<string> ids;
                stringstream ss(event[2]);
                string token;
                while (ss >> token) {
                    ids.push_back(token);
                }

                for (string id : ids) {
                    if (id == "ALL") {
                        for (int i = 0; i < mentionCount.size(); i++) {
                            mentionCount[i]++;
                        }
                    } else if (id == "HERE") {
                        for (int i = 0; i < mentionCount.size(); i++) {
                            if (offlineTime[i] == 0 ||
                                offlineTime[i] + 60 <= timestamp) {
                                mentionCount[i]++;
                            }
                        }
                    } else {
                        mentionCount[stoi(id.substr(2))]++;
                    }
                }

            } else {
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }
};
