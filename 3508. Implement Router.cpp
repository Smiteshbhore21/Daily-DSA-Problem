class Router {
public:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packetStore;
    unordered_map<int, vector<int>> destTimeMap;
    queue<string> que;

    Router(int memoryLimit) { MAX_SIZE = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + '_' + to_string(destination) + '_' +
                     to_string(timestamp);
        if (packetStore.find(key) != packetStore.end())
            return false;
        if (que.size() == MAX_SIZE) {
            forwardPacket();
        }
        packetStore[key] = {source, destination, timestamp};
        que.push(key);
        destTimeMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {};
        string key = que.front();
        que.pop();
        vector<int> packet = packetStore[key];
        packetStore.erase(key);
        int D = packet[1];
        destTimeMap[D].erase(destTimeMap[D].begin());
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimeMap.find(destination);

        if (it == destTimeMap.end() || it->second.empty())
            return 0;

        vector<int>& timeStamps = it->second;
        int i = lower_bound(timeStamps.begin(), timeStamps.end(), startTime) -
                timeStamps.begin();
        int j = upper_bound(timeStamps.begin(), timeStamps.end(), endTime) -
                timeStamps.begin();
        return j - i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

// TLE -->
// class Router {
// public:
//     queue<vector<int>> packets;
//     unordered_set<string> sourceMap;
//     int memoryLimit;
//     Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

//     bool addPacket(int source, int destination, int timestamp) {
//         string packet = to_string(source) + '*' + to_string(destination) +
//         '*' +
//                         to_string(timestamp);
//         if (sourceMap.count(packet)) {
//             return false;
//         }
//         if (packets.size() == memoryLimit) {
//             forwardPacket();
//         }
//         sourceMap.insert(packet);
//         packets.push({source, destination, timestamp});
//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (packets.empty())
//             return {};
//         vector<int> forwardP = packets.front();
//         string packet = to_string(forwardP[0]) + '*' + to_string(forwardP[1])
//         +
//                         '*' + to_string(forwardP[2]);
//         sourceMap.erase(packet);
//         packets.pop();
//         return forwardP;
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         int count = 0;
//         for (auto& src : sourceMap) {
//             int s1 = src.find('*');
//             int s2 = src.find('*', s1 + 1);
//             int d = stoi(src.substr(s1 + 1, s2 - s1 - 1));
//             int t = stoi(src.substr(s2 + 1));
//             if (d == destination && t >= startTime && t <= endTime)
//                 count++;
//         }
//         return count;
//     }
// };

// /**
//  * Your Router object will be instantiated and called as such:
//  * Router* obj = new Router(memoryLimit);
//  * bool param_1 = obj->addPacket(source,destination,timestamp);
//  * vector<int> param_2 = obj->forwardPacket();
//  * int param_3 = obj->getCount(destination,startTime,endTime);
//  */
