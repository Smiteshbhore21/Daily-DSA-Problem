class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= derived[i];
        return ans % 2 == 0;

        //1->          return accumulate(derived.begin(), derived.end(), 0)%2==0;

        //2->          int countOnes = count(derived.begin(), derived.end());        
        //            return countOnes % 2 == 0;


        //3->           int ans = 0;
        //            for (int i : derived)
        //              ans ^= i;
        //            return ans % 2 == 0;
    }
};
