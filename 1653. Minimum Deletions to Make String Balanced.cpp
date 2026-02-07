class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ops = 0;
        for (const char& ch : s) {
            if (!st.empty() && st.top() == 'b' && ch == 'a') {
                ops++;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return ops;
    }
};
