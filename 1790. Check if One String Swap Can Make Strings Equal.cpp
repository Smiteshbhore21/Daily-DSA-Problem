class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), count = 0;
        vector<int> hashA(26, 0), hashB(26, 0);
        for (int i = 0; i < n; i++) {
            int ind1 = s1[i] - 'a';
            int ind2 = s2[i] - 'a';
            if (ind1 != ind2)
                count++;
            hashA[ind1]++;
            hashB[ind2]++;
        }
        if (count > 2)
            return false;

        for (int i = 0; i < 26; i++)
            if (hashA[i] != hashB[i])
                return false;

        return true;
    }
};
