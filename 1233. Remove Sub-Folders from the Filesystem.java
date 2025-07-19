class Solution {
    public List<String> removeSubfolders(String[] folder) {
        int n = folder.length;
        HashSet<String> setStrings = new HashSet<>(Arrays.asList(folder));
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int nameSize = folder[i].length() - 1;
            while (nameSize != -1) {
                if (folder[i].charAt(nameSize) != '/') {
                    nameSize--;
                } else {
                    String mainFolder = folder[i].substring(0, nameSize);
                    if (setStrings.contains(mainFolder)) {
                        break;
                    }
                    nameSize--;
                }
            }
            if (nameSize == -1)
                ans.add(folder[i]);
        }
        return ans;
    }
}
