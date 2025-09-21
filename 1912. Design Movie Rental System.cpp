using P = pair<int, int>;
class MovieRentingSystem {
public:
    unordered_map<int, set<P>> available;        // movie -> set<price, shop>
    unordered_map<int, set<P>> movieToShopPrice; // movie -> set<shop, price>
    set<array<int, 3>> rentedSet;                // price, shop, movie
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            available[movie].insert({price, shop});
            movieToShopPrice[movie].insert({shop, price});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        if (available.count(movie)) {
            for (auto& [_, shop] : available[movie]) {
                result.push_back(shop);
                count++;
                if (count == 5) {
                    break;
                }
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].erase({price, shop});
        rentedSet.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;
        available[movie].insert({price, shop});
        rentedSet.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int cnt = 0;
        for (auto& [price, shop, movie] : rentedSet) {
            result.push_back({shop, movie});
            cnt++;
            if (cnt == 5) {
                break;
            }
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

// TLE --> 41/42 Passed
// using p = pair<int, int>;
// class MovieRentingSystem {
// public:
//     int shops;
//     unordered_map<int, priority_queue<p, vector<p>, greater<p>>> moviesMap;
//     unordered_map<int, unordered_set<int>> shopMap;
//     unordered_map<int, unordered_set<int>> rented;
//     vector<unordered_map<int, int>> priceByShop;
//     set<array<int, 3>> rentedSet;
//     MovieRentingSystem(int n, vector<vector<int>>& entries) {
//         shops = n;
//         priceByShop.resize(n);
//         for (vector<int>& entry : entries) {
//             int shop = entry[0];
//             int movie = entry[1];
//             int price = entry[2];
//             priceByShop[shop][movie] = price;
//             moviesMap[movie].push({price, shop});
//             shopMap[shop].insert(movie);
//         }
//     }

//     vector<int> search(int movie) {
//         if (moviesMap.find(movie) == moviesMap.end()) {
//             return {};
//         }
//         auto pq = moviesMap[movie];
//         vector<int> top5;
//         while (!pq.empty() && top5.size() < 5) {
//             int shop = pq.top().second;
//             if (shopMap[shop].count(movie) && rented[shop].count(movie) == 0)
//             {
//                 if (top5.empty() || top5.back() != shop)
//                     top5.push_back(shop);
//             }
//             pq.pop();
//         }
//         return top5;
//     }

//     void rent(int shop, int movie) {
//         int price = priceByShop[shop][movie];
//         rentedSet.insert({price, shop, movie});
//         shopMap[shop].erase(movie);
//         rented[shop].insert(movie);
//     }

//     void drop(int shop, int movie) {
//         int price = priceByShop[shop][movie];
//         auto it = rentedSet.find({price, shop, movie});
//         if (it != rentedSet.end())
//             rentedSet.erase(it);
//         shopMap[shop].insert(movie);
//         rented[shop].erase(movie);
//         moviesMap[movie].push({price, shop});
//     }

//     vector<vector<int>> report() {
//         vector<vector<int>> ans;
//         int cnt = 0;
//         for (auto it = rentedSet.begin(); it != rentedSet.end() && cnt < 5;
//              ++it, ++cnt) {
//             int shop = (*it)[1];
//             int movie = (*it)[2];
//             ans.push_back({shop, movie});
//         }
//         return ans;
//     }
// };

// /**
//  * Your MovieRentingSystem object will be instantiated and called as such:
//  * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
//  * vector<int> param_1 = obj->search(movie);
//  * obj->rent(shop,movie);
//  * obj->drop(shop,movie);
//  * vector<vector<int>> param_4 = obj->report();
//  */
