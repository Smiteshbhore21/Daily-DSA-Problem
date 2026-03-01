class Solution {
    public int minPartitions(String n) {
        int result = 0;
        for(char ch : n.toCharArray()){
            result = Math.max(result, ch - '0');
        }
        return result;
    }
}
