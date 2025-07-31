// O(n * 32) -->
// size of set will be max at 32 as there is only 32 bits to turn ON 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev, curr, result;
        for (int i = 0; i < n; i++) {
            for (int x : prev) {
                curr.insert(arr[i] | x);
                result.insert(arr[i] | x);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};

// TLE -->
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         set<int> uniq;
//         for (int i = 0; i < n; i++) {
//             int bitOR = 0;
//             for (int j = i; j < n; j++) {
//                 bitOR |= arr[j];
//                 uniq.insert(bitOR);
//             }
//         }
//         return uniq.size();
//     }
// };
