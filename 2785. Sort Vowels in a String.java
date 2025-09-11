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

//CPP -->
// class Solution {
// public:
//     string sortVowels(string s) {
//         size_t n = s.size();
//         vector<int> upper_vowels(26, 0), lower_vowels(26, 0);
//         int upperC = 0;

//         for (const char& ch : s) {
//             if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//                 lower_vowels[ch - 'a']++;
//             } else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
//                        ch == 'U') {
//                 upper_vowels[ch - 'A']++;
//                 upperC++;
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             char ch = s[i];
//             if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//                 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
//                 if (upperC != 0) {
//                     for (int j = 0; j < 26; j++) {
//                         if (upper_vowels[j] != 0) {
//                             s[i] = (char)(j + 65);
//                             upperC--;
//                             upper_vowels[j]--;
//                             break;
//                         }
//                     }
//                 } else {
//                     for (int j = 0; j < 26; j++) {
//                         if (lower_vowels[j] != 0) {
//                             s[i] = (char)(j + 97);
//                             lower_vowels[j]--;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         return s;
//     }
// };
