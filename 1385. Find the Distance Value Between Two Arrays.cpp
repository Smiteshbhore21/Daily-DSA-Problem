class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        sort(begin(arr2), end(arr2));

        int result = 0;
        for (int i = 0; i < n1; i++) {
            bool allValid = true;

            int l = 0;
            int r = n2 - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int& x = arr1[i];

                if (arr2[mid] >= x - d && arr2[mid] <= x + d) {
                    allValid = false;
                    break;
                } else if (arr2[mid] < x - d) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (allValid)
                result++;
        }

        return result;
    }
};
