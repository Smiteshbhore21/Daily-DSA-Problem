class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obst;
        for (vector<int>& obs : obstacles) {
            string coord = to_string(obs[0]) + '_' + to_string(obs[1]);
            obst.insert(coord);
        }
        int n = commands.size();
        pair<int, int> robot;
        pair<int, int> dir = {0, 1}; // Pointing North
        int maxD = 0;
        for (int i = 0; i < n; i++) {
            if (commands[i] == -2) {
                dir = {-dir.second, dir.first};
            } else if (commands[i] == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int step = 0; step < commands[i]; step++) {
                    int newX = robot.first + dir.first;
                    int newY = robot.second + dir.second;

                    string key = to_string(newX) + '_' + to_string(newY);

                    if (obst.count(key)) {
                        break;
                    }

                    robot.first = newX;
                    robot.second = newY;
                }
            }
            maxD = max(maxD, (robot.first * robot.first) +
                                 (robot.second * robot.second));
        }
        return maxD;
    }
};
