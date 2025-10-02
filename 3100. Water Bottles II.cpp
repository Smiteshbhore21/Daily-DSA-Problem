class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = numBottles;
        int emptyBottles = numBottles;
        for (numExchange; numExchange <= emptyBottles; numExchange++) {
            drink++;
            emptyBottles -= (numExchange - 1);
        }
        return drink;
    }
};
