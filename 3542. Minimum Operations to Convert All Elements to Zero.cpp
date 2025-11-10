class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ops = 0;
        for (int& num : nums) {

            while (!st.empty() && st.top() > num) {
                st.pop();
            }

            if (num == 0)
                continue;

            if (st.empty() || st.top() < num) {
                ops++;
                st.push(num);
            }
        }
        return ops;
    }
};
