class Solution {
  public:
    vector<int> findSum(int n) {
        // Code here
        int evenSum = (n/2)*((n/2)+1);
        vector<int> ans = {(n*(n+1)/2)-evenSum, evenSum};
        return ans;
    }
};
