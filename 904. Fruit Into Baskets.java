class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer, Integer> baskets = new HashMap<>();
        int n = fruits.length;
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            baskets.put(fruits[j], baskets.getOrDefault(fruits[j], 0) + 1);
            if (baskets.size() > 2) {
                baskets.put(fruits[i], baskets.get(fruits[i]) - 1);
                if (baskets.get(fruits[i]) == 0)
                    baskets.remove(fruits[i]);
                i++;
            }
            int countFruit = (j - i + 1);
            ans = Math.max(ans, countFruit);
            j++;
        }
        return ans;
    }
}
