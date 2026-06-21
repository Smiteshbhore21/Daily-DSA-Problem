class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxEle = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxEle + 1, 0);
        for (int& cost : costs) {
            freq[cost]++;
        }

        int n = freq.size();
        int canBuy = 0;
        for (int cost = 1; cost < n; cost++) {
            int take = min(freq[cost], coins / cost);
            canBuy += take;
            coins -= take * cost;
        }
        return canBuy;
    }
};

// Time --> O(N*log(N))
// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         sort(costs.begin(), costs.end());
//         int count = 0;
//         for (int& cost : costs) {
//             coins -= cost;
//             if (coins < 0) {
//                 return count;
//             }
//             count++;
//         }
//         return count;
//     }
// };
