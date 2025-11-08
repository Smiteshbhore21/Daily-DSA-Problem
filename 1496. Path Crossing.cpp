class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        for (const char& ch : path) {
            if (ch == 'N')
                ++y;
            else if (ch == 'S')
                --y;
            else if (ch == 'E')
                ++x;
            else if (ch == 'W')
                --x;
            if (visited.count({x, y}))
                return true;
            visited.insert({x, y});
        }
        return false;
    }
};
