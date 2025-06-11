class Solution {
public:
    int getState(int countA, int countB) {
        int parityA = countA % 2, parityB = countB % 2;
        if (parityA == 0 && parityB == 0)
            return 0; // even even (00)
        if (parityA == 0 && parityB == 1)
            return 1; // even odd (01)
        if (parityA == 1 && parityB == 0)
            return 2; // odd even (10)
        return 3;     // odd odd (11)
    }
    int maxDifference(string s, int k) {
        int n = s.size();

        int result = INT_MIN;

        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b)
                    continue;
                vector<int> stateMinPrev_a_b(4, INT_MAX);
                int countA = 0, countB = 0;
                int prevA = 0, prevB = 0;
                int l = -1, r = 0;
                while (r < n) {
                    countA += (s[r] == a) ? 1 : 0;
                    countB += (s[r] == b) ? 1 : 0;
                    while (r - l >= k && countB - prevB >= 2 &&
                           countB - prevA >= 1) {
                        int leftState = getState(prevA, prevB);
                        stateMinPrev_a_b[leftState] =
                            min(stateMinPrev_a_b[leftState], prevA - prevB);
                        l++;
                        prevA += s[l] == a ? 1 : 0;
                        prevB += s[l] == b ? 1 : 0;
                    }
                    int rightState = getState(countA, countB);
                    int bestLeftState = rightState ^ 2;
                    int bestMinDiffValueLeft = stateMinPrev_a_b[bestLeftState];

                    if (bestMinDiffValueLeft != INT_MAX) {
                        result = max(result,
                                     (countA - countB) - bestMinDiffValueLeft);
                    }
                    r++;
                }
            }
        }
        return result;
    }
};
