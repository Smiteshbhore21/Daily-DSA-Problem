class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int operations = 0;
        int prev = 0;
        for (const int& curr : target) {
            if (curr <= prev) {
                prev = curr;
                continue;
            }
            operations += (curr - prev);
            prev = curr;
        }
        return operations;
    }
};
