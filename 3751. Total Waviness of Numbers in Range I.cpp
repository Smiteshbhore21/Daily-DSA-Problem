class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;

        for (int i = num1; i <= num2; i++) {
            count += countWave(i);
        }

        return count;
    }

    int countWave(int num) {
        string str = to_string(num);
        int count = 0;
        int n = str.length();

        if (n < 3)
            return 0;

        for (int i = 1; i < n - 1; i++) {
            if (str[i - 1] > str[i] && str[i + 1] > str[i])
                count++;

            if (str[i - 1] < str[i] && str[i + 1] < str[i])
                count++;
        }

        return count;
    }
};
