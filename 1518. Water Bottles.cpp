class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+((numBottles-1)/(numExchange-1));
    }
};

// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int drink = numBottles;
//         int emptyBottles = numBottles;
//         while (emptyBottles >= numExchange) {
//             drink += (emptyBottles / numExchange);
//             emptyBottles =
//                 (emptyBottles % numExchange) + (emptyBottles / numExchange);
//         }
//         return drink;
//     }
// };
