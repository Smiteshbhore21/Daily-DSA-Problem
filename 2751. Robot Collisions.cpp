class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> robots(n);
        iota(begin(robots), end(robots), 0); // 0, 1, 2, 3, ..., n-1

        sort(robots.begin(), robots.end(), [&](const int& i, const int& j) {
            return positions[i] < positions[j];
        });

        vector<int> result;
        stack<int> st;
        for (int& currIdx : robots) {
            if (directions[currIdx] == 'R')
                st.push(currIdx);
            else {
                while (!st.empty() && healths[currIdx]) {
                    int top_idx = st.top();
                    st.pop();
                    if (healths[top_idx] > healths[currIdx]) {
                        healths[top_idx]--;
                        healths[currIdx] = 0;
                        st.push(top_idx);
                    } else if (healths[top_idx] < healths[currIdx]) {
                        healths[currIdx]--;
                        healths[top_idx] = 0;
                    } else {
                        healths[currIdx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                result.push_back(healths[i]);
        }
        return result;
    }
};
