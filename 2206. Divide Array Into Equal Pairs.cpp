class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;
        for (int& x : nums) {
            if (st.find(x) != st.end())
                st.erase(x);
            else
                st.insert(x);
        }
        return st.empty();
    }
};
