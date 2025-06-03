// BFS -->
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int candiesGot = 0;
        queue<int> bfs, foundBoxes;
        for (int& x : initialBoxes) {
            bfs.push(x);
        }

        //BFS on already opened boxes
        while (!bfs.empty()) {
            int box = bfs.front();
            bfs.pop();
            if (status[box]) {
                candiesGot += candies[box];
                candies[box] = 0;
            } else {
                foundBoxes.push(box);
                continue;
            }
            for (int i = 0; i < keys[box].size(); i++) {
                status[keys[box][i]] = 1;
            }
            for (int i = 0; i < containedBoxes[box].size(); i++) {
                bfs.push(containedBoxes[box][i]);
            }
        }

        //BFS on found key boxes
        while (!foundBoxes.empty()) {
            int box = foundBoxes.front();
            foundBoxes.pop();
            if (status[box]) {
                candiesGot += candies[box];
                candies[box] = 0;
            } else {
                continue;
            }
            for (int i = 0; i < keys[box].size(); i++) {
                status[keys[box][i]] = 1;
            }
            for (int i = 0; i < containedBoxes[box].size(); i++) {
                foundBoxes.push(containedBoxes[box][i]);
            }
        }
        return candiesGot;
    }
};

// DFS -->
// class Solution {
// public:
//     int maxCandies(vector<int>& status, vector<int>& candies,
//                    vector<vector<int>>& keys,
//                    vector<vector<int>>& containedBoxes,
//                    vector<int>& initialBoxes) {
//         int candiesGot = 0;
//         stack<int> dfs, foundBoxes;
//         for (int& x : initialBoxes) {
//             dfs.push(x);
//         }

//         //DFS on already opened boxes
//         while (!dfs.empty()) {
//             int box = dfs.top();
//             dfs.pop();
//             if (status[box]) {
//                 candiesGot += candies[box];
//                 candies[box] = 0;
//             } else {
//                 foundBoxes.push(box);
//                 continue;
//             }
//             for (int i = 0; i < keys[box].size(); i++) {
//                 status[keys[box][i]] = 1;
//             }
//             for (int i = 0; i < containedBoxes[box].size(); i++) {
//                 dfs.push(containedBoxes[box][i]);
//             }
//         }

//         //DFS on found key boxes
//         while (!foundBoxes.empty()) {
//             int box = foundBoxes.top();
//             foundBoxes.pop();
//             if (status[box]) {
//                 candiesGot += candies[box];
//                 candies[box] = 0;
//             } else {
//                 continue;
//             }
//             for (int i = 0; i < keys[box].size(); i++) {
//                 status[keys[box][i]] = 1;
//             }
//             for (int i = 0; i < containedBoxes[box].size(); i++) {
//                 foundBoxes.push(containedBoxes[box][i]);
//             }
//         }
//         return candiesGot;
//     }
// };
