class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        if (n == 1)
            return questions[0][0];
        vector<long long> t(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if ((i + questions[i][1] + 1) < n)
                t[i] =
                    max(questions[i][0] + t[i + questions[i][1] + 1], t[i + 1]);
            else {
                if (i + 1 < n)
                    t[i] = max(questions[i][0] * 1ll, t[i + 1]);
                else
                    t[i] = questions[i][0];
            }
        }
        return t[0];
    }
};

// class Solution {

//     long long findMaxPoints(vector<vector<int>>& questions, int pos,
//                             vector<long long>& mem) {
//         if (pos >= questions.size())
//             return 0;
//         if (mem[pos] != -1)
//             return mem[pos];
//         long long include =
//             questions[pos][0] +
//             findMaxPoints(questions, pos + questions[pos][1] + 1, mem);
//         long long exclude = findMaxPoints(questions, pos + 1, mem);
//         return mem[pos] = max(exclude, include);
//     }

// public:
//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = questions.size();
//         vector<long long> mem(n, -1);
//         return findMaxPoints(questions, 0, mem);
//     }
// };
