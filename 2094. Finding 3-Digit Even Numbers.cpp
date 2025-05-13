class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> numCount(11), ans;
        for (int& x : digits) {
            numCount[x]++;
        }
        for (int i = 1; i < 10; i++) {
            if (numCount[i] == 0)
                continue;
            numCount[i]--;
            for (int j = 0; j < 10; j++) {
                if (numCount[j] == 0)
                    continue;
                numCount[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (numCount[k] == 0)
                        continue;
                    numCount[k]--;
                    int num = (i * 100) + (j * 10) + k;
                    ans.push_back(num);
                    numCount[k]++;
                }
                numCount[j]++;
            }
            numCount[i]++;
        }
        return ans;
    }
};
