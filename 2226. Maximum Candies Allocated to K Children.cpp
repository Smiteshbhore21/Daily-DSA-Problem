class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long start = 1, end = *max_element(candies.begin(), candies.end()),
                  mid = 0, maxCandies = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            long long count = 0;
            for (int& x : candies) {
                count = count + (x / mid);
            }
            if (count >= k) {
                start = mid + 1;
                maxCandies = mid;
            } else {
                end = mid - 1;
            }
        }
        return maxCandies;
    }
};
