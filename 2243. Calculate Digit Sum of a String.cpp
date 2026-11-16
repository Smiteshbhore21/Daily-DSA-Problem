
class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();

        while (n > k) {
            string new_s = "";

            int totalRounds = (n + k - 1) / k;

            for (int round = 0; round < totalRounds; round++) {
                int sum = 0;

                for (int i = round * k; i < min((round + 1) * k, n); i++) {
                    sum += s[i] - '0';
                }

                new_s += to_string(sum);
            }

            s = new_s;
            n = s.length();
        }

        return s;
    }
};
