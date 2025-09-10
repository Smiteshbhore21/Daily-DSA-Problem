class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> sadPeoples;
        for (auto& friends : friendships) {
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> langeSet(languages[u].begin(),
                                        languages[u].end());
            bool canTalk = false;
            for (int lang : languages[v]) {
                if (langeSet.count(lang)) {
                    canTalk = !canTalk;
                    break;
                }
            }
            if (!canTalk) {
                sadPeoples.insert(u);
                sadPeoples.insert(v);
            }
        }
        vector<int> language(n + 1, 0);
        int mostKnownLang = 0;
        for (int user : sadPeoples) {
            for (int lang : languages[user]) {
                language[lang]++;
                mostKnownLang = max(mostKnownLang,  language[lang]);
            }
        }
        return sadPeoples.size() - mostKnownLang;
    }
};
