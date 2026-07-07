using ll = long long;
class Solution {
public:
    int sum = 0;

    long long sumAndMultiply(ll n) {
        ll nonZero = nonZeroDigits(n);
        return nonZeroDigits(nonZero) * sum;
    }

    ll nonZeroDigits(ll n) {
        sum = 0;
        ll result = 0;
        while (n) {
            int rem = n % 10;
            if (rem == 0) {
                n /= 10;
                continue;
            }
            result = rem + (result * 10);
            sum += rem;
            n /= 10;
        }
        return result;
    }
};
