// DSU --> O(N+M)
class Solution {
    int find(vector<int>& dsu, int v) {
        if (dsu[v] == -1)
            return v;
        return dsu[v] = find(dsu, dsu[v]);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> dsu(26, -1);
        int n = s1.size(), m = baseStr.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            int par1 = find(dsu, s1[i] - 'a'), par2 = find(dsu, s2[i] - 'a');

            if (par1 == par2)
                continue;

            if (par1 > par2)
                dsu[par1] = par2;
            else
                dsu[par2] = par1;
        }
        string ans = "";
        for (int i = 0; i < m; i++) {
            int parent = find(dsu, baseStr[i] - 'a');
            ans += parent + 97;
        }
        return ans;
    }
};

// DFS --> O(M*(V+E))
//  class Solution {
//  public:
//      char DFSfindMinChar(unordered_map<char, vector<char>>& adj, char&
//      curr_ch,
//                          vector<int>& visited) {
//          visited[curr_ch - 'a'] = 1;
//          char minChar = curr_ch;
//          for (char& v : adj[curr_ch]) {
//              if (visited[v - 'a'] == 0) {
//                  minChar = min(minChar, DFSfindMinChar(adj, v, visited));
//              }
//          }
//          return minChar;
//      }

//     string smallestEquivalentString(string s1, string s2, string baseStr) {
//         unordered_map<char, vector<char>> adj;
//         int n = s1.size(), m = baseStr.size();
//         for (int i = 0; i < n; i++) {
//             if (s1[i] == s2[i]) {
//                 adj[s1[i]].push_back(s2[i]);
//             } else {
//                 adj[s1[i]].push_back(s2[i]);
//                 adj[s2[i]].push_back(s1[i]);
//             }
//         }
//         string ans = "";
//         for (int i = 0; i < m; i++) {
//             vector<int> visited(26, 0);
//             ans += DFSfindMinChar(adj, baseStr[i], visited);
//         }
//         return ans;
//     }
// };
