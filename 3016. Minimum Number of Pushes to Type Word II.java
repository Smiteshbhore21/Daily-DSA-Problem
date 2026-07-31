class Solution {
    public int minimumPushes(String word) {
        int[] map = new int[26];

        for (char ch : word.toCharArray()) {
            map[ch - 'a']++;
        }

        map = Arrays.stream(map)
                .boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(Integer::intValue)
                .toArray(); // Descending Sort

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += (map[i] * (i / 8 + 1));
        }

        return result;
    }
}
