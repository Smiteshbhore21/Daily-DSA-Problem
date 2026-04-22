class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        int n = queries[0].length();

        List<String> result = new ArrayList<>();

        for (String query : queries) {
            for (String dictWord : dictionary) {
                int diff = 0;

                for (int i = 0; i < n; i++) {
                    if (dictWord.charAt(i) != query.charAt(i)) {
                        diff++;
                    }
                    if (diff == 3)
                        break;
                }

                if (diff == 3)
                    continue;
                else {
                    result.add(query);
                    break;
                }
            }
        }

        return result;
    }
}
