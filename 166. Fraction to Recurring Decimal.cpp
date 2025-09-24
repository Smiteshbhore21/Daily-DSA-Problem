class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator)
            return "0";

        string result = "";

        if ((1ll * numerator * denominator) < 0)
            result += '-';

        long long absNumerator = labs(numerator),
                  absDenominator = labs(denominator);

        result += to_string(absNumerator / absDenominator);
        long long remainder = absNumerator % absDenominator;

        if (remainder == 0)
            return result;

        result += '.';
        unordered_map<int, int> remainders;

        while (remainder != 0) {
            if (remainders.find(remainder) != remainders.end()) {
                result.insert(remainders[remainder], "(");
                result += ')';
                return result;
            }
            remainders[remainder] = result.length();
            remainder *= 10;
            result += to_string(remainder / absDenominator);
            remainder = remainder % absDenominator;
        }

        return result;
    }
};
