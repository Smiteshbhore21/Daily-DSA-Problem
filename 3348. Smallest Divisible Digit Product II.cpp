using ll = long long;
class Solution {
public:
    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t;

        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) {
                temp /= primeFact;
            }
        }

        if (temp != 1) {
            return "-1";
        }

        vector<ll> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if (digit == 0)
                break;

            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        if (remainingFactor[n] == 1) {
            return num;
        }

        int zeroIdx = num.find('0');
        if (zeroIdx == string::npos) {
            zeroIdx = n - 1;
        }

        for (int i = zeroIdx; i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll furtherRequired = required / gcd(required, digit);
                string requiredNumber =
                    freeSlotsFiller(furtherRequired, freeSlots);

                if (requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) + char(digit + '0') +
                           requiredNumber;
                }
            }
        }

        return freeSlotsFiller(t, n + 1);
    }

    string freeSlotsFiller(ll required, int len) {
        string str;

        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        while (str.length() < len) {
            str.push_back('1');
        }

        reverse(str.begin(), str.end());

        return str;
    }
};
