class Solution {

    class Node {
        public int pre;
        public int suf;
        public int maxLen;
        public char leftChar;
        public char rightChar;

        Node(int pre, int suf, int maxLen,
                char leftChar, char rightChar) {
            this.pre = pre;
            this.suf = suf;
            this.maxLen = maxLen;
            this.leftChar = leftChar;
            this.rightChar = rightChar;
        }
    }

    int n;
    Node[] segmentTree;

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        n = s.length();
        segmentTree = new Node[4 * n];

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.length;

        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters.charAt(i);
            update(0, 0, n - 1, pos, ch);

            result[i] = segmentTree[0].maxLen;
        }

        return result;
    }

    public void buildSegmentTree(int i, int l, int r, String s) {
        if (l == r) {
            char ch = s.charAt(l);
            segmentTree[i] = new Node(1, 1, 1, ch, ch);
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segmentTree[i] = merge(segmentTree[2 * i + 1], segmentTree[2 * i + 2], mid - l + 1, r - mid);
    }

    public void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segmentTree[i] = new Node(1, 1, 1, ch, ch);
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segmentTree[i] = merge(segmentTree[2 * i + 1], segmentTree[2 * i + 2], mid - l + 1, r - mid);
    }

    public Node merge(Node L, Node R, int leftLen, int rightLen) {
        Node res = new Node(0,
                0,
                0,
                L.leftChar,
                R.rightChar);

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = L.suf + R.suf;
        }

        res.maxLen = Math.max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = Math.max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }
}
