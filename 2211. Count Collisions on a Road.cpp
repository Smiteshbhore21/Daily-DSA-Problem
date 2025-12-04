class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int start = 0, end = n - 1;

        while (start < n && directions[start] == 'L') {
            start++;
        }

        while (end > -1 && directions[end] == 'R') {
            end--;
        }
        int collisions = 0;
        for (start; start <= end; start++) {
            if (directions[start] != 'S')
                collisions++;
        }
        return collisions;
    }
};

// class Solution {
// public:
//     int countCollisions(string directions) {
//         int n = directions.size();
//         int collisions = 0;
//         char prevCarDir = directions[0];
//         int rNotCollide = directions[0] == 'R' ? 1 : 0;
//         for (int i = 1; i < n; i++) {
//             if ((prevCarDir == 'R' && directions[i] == 'L')) {
//                 collisions += 2;
//                 collisions += (rNotCollide - 1);
//                 rNotCollide = 0;
//                 prevCarDir = 'S';
//             } else if ((prevCarDir == 'S' && directions[i] == 'L')) {
//                 collisions++;
//                 prevCarDir = 'S';
//             } else if ((prevCarDir == 'R' && directions[i] == 'S')) {
//                 collisions = collisions + rNotCollide;
//                 rNotCollide = 0;
//                 prevCarDir = 'S';
//             } else if (directions[i] == 'R') {
//                 rNotCollide++;
//                 prevCarDir = directions[i];
//             } else {
//                 prevCarDir = directions[i];
//             }
//         }
//         return collisions;
//     }
// };
