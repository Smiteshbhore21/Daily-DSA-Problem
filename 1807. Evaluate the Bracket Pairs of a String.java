class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int n = s.length();

        HashMap<String, String> knowledgeMapping = new HashMap<>();

        for (List<String> keyVal : knowledge) {
            knowledgeMapping.put(keyVal.get(0), keyVal.get(1));
        }

        StringBuilder result = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                StringBuilder temp = new StringBuilder("");
                i++;
                while (s.charAt(i) != ')') {
                    temp.append(s.charAt(i));
                    i++;
                }
                if (knowledgeMapping.containsKey(temp.toString())) {
                    result.append(knowledgeMapping.get(temp.toString()));
                } else {
                    result.append('?');
                }
            } else {
                result.append(s.charAt(i));
            }
        }

        return result.toString();
    }
}
