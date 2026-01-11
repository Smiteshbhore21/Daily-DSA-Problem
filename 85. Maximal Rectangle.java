class Solution {
    public int maximalRectangle(char[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int[] height = new int[cols];

        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == '1') {
                height[i] = 1;
            }
        }
        int result = calculateMaxArea(height);

        for (int row = 1; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            result = Math.max(result, calculateMaxArea(height));
        }

        return result;
    }

    int[] getNSR(int[] height) {
        Stack<Integer> st = new Stack<>();

        int n = height.length;

        int[] NSR = new int[n];

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n;
            } else {
                while (!st.empty() && height[st.peek()] >= height[i]) {
                    st.pop();
                }
                if (st.empty())
                    NSR[i] = n;
                else
                    NSR[i] = st.peek();
            }
            st.push(i);
        }
        return NSR;
    }

    int[] getNSL(int[] height) {
        Stack<Integer> st = new Stack<>();

        int n = height.length;

        int[] NSL = new int[n];

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.peek()] >= height[i]) {
                    st.pop();
                }
                if (st.empty())
                    NSL[i] = -1;
                else
                    NSL[i] = st.peek();
            }
            st.push(i);
        }
        return NSL;
    }

    private int calculateMaxArea(int[] height) {
        int[] NSR = getNSR(height);
        int[] NSL = getNSL(height);

        int[] width = new int[height.length];

        int maxArea = 0;

        for(int i = 0; i < height.length; i++){
            width[i] = NSR[i] - NSL[i] - 1;
        }

        for(int i = 0; i < height.length; i++){
            int a = width[i] * height[i];

            maxArea = Math.max(maxArea, a);
        }
        return maxArea;
    }
}
