class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int result = 0;
        for (String str : patterns) {
            if (word.contains(str))
                result++;
        }
        return result;
    }
}
