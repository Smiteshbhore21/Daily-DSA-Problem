class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();

        int oneCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                oneCount++;
            }
        }

        List<Integer> zeroBlocks = new ArrayList<>();

        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                int start = i;
                while (i < n && s.charAt(i) == '0')
                    i++;

                zeroBlocks.add(i - start);
            } else {
                i++;
            }
        }

        int result = 0;
        for (int j = 0; j < zeroBlocks.size() - 1; j++) {
            result = Math.max(result, zeroBlocks.get(j) + zeroBlocks.get(j + 1));
        }

        return result + oneCount;
    }
}
