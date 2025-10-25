class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int sumTillDay = week * 28 + 7 * (week * (week - 1) / 2);
        int extraDays = day * (1 + week) + (day * (day - 1) / 2);
        return sumTillDay + extraDays;
    }
};
