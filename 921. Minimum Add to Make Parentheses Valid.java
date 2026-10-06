class Solution {
    public int minAddToMakeValid(String s) {
        int count = 0;

        int result = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(')
                count++;
            else if (ch == ')')
                count--;

            if (count < 0) {
                result += Math.abs(count);
                count = 0;
            }
        }

        result += Math.abs(count);

        return result;
    }
}
