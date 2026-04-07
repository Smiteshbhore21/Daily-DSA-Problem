class Robot {
public:
    int idx = 0;
    bool isMoved = false;
    vector<vector<int>> pos;
    Robot(int width, int height) {
        for (int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0}); // 0 -> East
        }
        for (int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1}); // 1 -> North
        }
        for (int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2}); // 2 -> West
        }
        for (int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3}); // 3 -> South
        }

        pos[0][2] =3;
    }

    void step(int num) {
        isMoved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos() { return {pos[idx][0], pos[idx][1]}; }

    string getDir() {
        if (!isMoved)
            return "East";

        if (pos[idx][2] == 0)
            return "East";
        if (pos[idx][2] == 1)
            return "North";
        if (pos[idx][2] == 2)
            return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
