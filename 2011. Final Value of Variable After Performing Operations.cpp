class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string& s : operations) {
            if (s[1] == '-') {
                X--;
            } else {
                X++;
            } 
        }
        return X;
    }
};
