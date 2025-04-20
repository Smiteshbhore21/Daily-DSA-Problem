class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size(), totalRabbits = 0;
        unordered_map<int, int> freq;

        for (int& x : answers)
            freq[x]++;

        for (auto& [x, c] : freq) {
            int groups = ceil((double)c / (x + 1));
            totalRabbits += (groups * (x + 1));
        }

        return totalRabbits;
    }
};
