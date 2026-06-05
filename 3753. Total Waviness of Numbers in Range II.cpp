using ll = long long;
class Solution {
public:
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    long long totalWaviness(long long num1, long long num2) {

        return func(num2) - func(num1 - 1);
    }

    ll func(ll num) {
        if (num < 100)
            return 0;

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    pair<ll, ll> solve(int curr, int prevPrev, int prev,
                       bool isLimitedWithActualNumber, bool isLeadingZero) {
        if (curr == n)
            return {1, 0};

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 &&
            prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev],
                        dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNum = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitedWithActualNumber ? s[curr] - '0' : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev = newIsLeadingZero ? -1 : digit;

            auto [remainTotalNums, remainTotalWaveScore] =
                solve(curr + 1, newPrevPrev, newPrev,
                      isLimitedWithActualNumber && (digit == limitDigit),
                      newIsLeadingZero);

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley)
                    totalWaveScore += remainTotalNums;
            }

            totalNum += remainTotalNums;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 &&
            prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev] = totalNum;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }
        return {totalNum, totalWaveScore};
    }
};
