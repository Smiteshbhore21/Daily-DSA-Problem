class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int* month =
            new int[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int prefixDays[13] = {0};
        for (int i = 1; i <= 12; i++) {
            prefixDays[i] = prefixDays[i - 1] + month[i - 1];
        }

        delete[] month;

        int result = 0;

        int aliceStartMonth = stoi(arriveAlice.substr(0, 2));
        int aliceEndMonth = stoi(leaveAlice.substr(0, 2));

        int bobStartMonth = stoi(arriveBob.substr(0, 2));
        int bobEndMonth = stoi(leaveBob.substr(0, 2));

        int startMax = max(
            prefixDays[aliceStartMonth - 1] + stoi(arriveAlice.substr(3, 2)),
            prefixDays[bobStartMonth - 1] + stoi(arriveBob.substr(3, 2)));

        int endMin =
            min(prefixDays[aliceEndMonth - 1] + stoi(leaveAlice.substr(3, 2)),
                prefixDays[bobEndMonth - 1] + stoi(leaveBob.substr(3, 2)));

        return max(0, endMin - startMax + 1);
    }
};
