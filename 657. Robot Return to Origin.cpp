class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> robot = {0, 0};
        for (const char& move : moves) {
            if (move == 'L') {
                robot.first--;
            } else if (move == 'R') {
                robot.first++;
            } else if (move == 'U') {
                robot.second++;
            } else {
                robot.second--;
            }
        }
        return robot == pair<int, int>{0, 0};
    }
};
