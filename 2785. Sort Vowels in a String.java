class Solution {
    public String sortVowels(String s) {
        int n = s.length();
        ArrayList<Character> vowels = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o'
                    || s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I'
                    || s.charAt(i) == 'O' || s.charAt(i) == 'U') {
                vowels.add(s.charAt(i));
            }
        }
        Collections.sort(vowels, Collections.reverseOrder());
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o'
                    || s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I'
                    || s.charAt(i) == 'O' || s.charAt(i) == 'U') {
                ans.append(vowels.get(vowels.size() - 1));
                vowels.remove(vowels.size() - 1);
            }else{
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
