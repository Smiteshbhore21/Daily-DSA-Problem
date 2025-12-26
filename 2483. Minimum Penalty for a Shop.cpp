class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int prefix = 0;
        for (char ch : customers) {
            if (ch == 'Y')
                prefix++;
        }
        int penalty = prefix;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'Y')
                prefix--;
            if (customers[i - 1] == 'N')
                prefix++;
            if (penalty > prefix) {
                penalty = prefix;
                ans = i;
            }
        }
        return ans;
    }
};
