class Solution {
    public boolean hasAllCodes(String s, int k) {
        HashSet<String> set = new HashSet<>();
        int n = s.length();
        int totalCodeK = (1 << k); // 2^k
        for (int i = k; i <= n; i++) {
            set.add(s.substring(i - k, i));
            if (totalCodeK == set.size())
                break;
        }
        return totalCodeK == set.size();
    }
}

// TLE --> O(n*m)
// class Solution {
//     public ArrayList<String> kBinaryCodes = new ArrayList<>();
//     public boolean hasAllCodes(String s, int k) {
//         generateAllKBinaryCode(k, "");
//         for(String str : kBinaryCodes){
//             if(!s.contains(str)){
//                 return false;
//             }
//         }
//         return true;
//     }
//     public void generateAllKBinaryCode(int k, String currStr){
//         if(currStr.length() == k){
//             kBinaryCodes.add(currStr);
//             return;
//         }
//         generateAllKBinaryCode(k, currStr.concat("0"));
//         generateAllKBinaryCode(k, currStr.concat("1"));
//     }
// }
