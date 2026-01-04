class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (const int& num : nums) {
            result += calcDivisor(num);
        }
        return result;
    }
    int calcDivisor(int num) {
        int divisors = 0;
        int divSum = 0;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                int otherFact = num / i;
                if (otherFact == i) {
                    divisors++;
                    divSum += i;
                } else {
                    divisors += 2;
                    divSum += (i + (otherFact));
                }
            }
            if (divisors > 4)
                return 0;
        }
        return (divisors == 4) ? divSum : 0;
    }
};
