class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int> freq(26);
        for (char ch : tiles)
            freq[ch - 'A']++;

        return backtrack(freq);
        // int n = tiles.size();
        // vector<bool> used(n);
        // set<string> setT;
        // backtrack(tiles, used, setT, "");
        // return setT.size() - 1;
    }
    int backtrack(vector<int>& freq) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if(!freq[i])    continue;
            count++;
            freq[i]--;
            count += backtrack(freq);
            freq[i]++;
        }
        return count;
    }

    // void backtrack(string tiles, vector<bool>& used, set<string>& setT,
    //                string cur) {
    //     if (setT.find(cur) != setT.end())
    //         return;

    //     setT.insert(cur);
    //     for (int i = 0; i < tiles.size(); i++) {
    //         if (used[i])
    //             continue;
    //         used[i] = true;

    //         backtrack(tiles, used, setT, cur + tiles[i]);
    //         used[i] = false;
    //     }
    // }
};
