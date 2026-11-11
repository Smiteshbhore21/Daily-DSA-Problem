using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        if (cost1 + cost2 <= costBoth) {
            return (1ll * need1 * cost1) + (1ll * need2 * cost2);
        }

        ll minNeed = min(need1, need2);

        if (minNeed == need1) {
            ll takenBoth = 1ll * need1 * costBoth;
            ll needMore = need2 - need1;
            return 1ll * takenBoth + (1ll * needMore * min(costBoth, cost2));
        }

        ll takenBoth = 1ll * need2 * costBoth;
        ll needMore = need1 - need2;
        return 1ll * takenBoth + (1ll * needMore * min(costBoth, cost1));
    }
};
