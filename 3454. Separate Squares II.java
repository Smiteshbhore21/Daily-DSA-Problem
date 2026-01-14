class Solution {

    class Event {
        double y;
        int type;
        int xStart;
        int xEnd;

        Event(double y, int type, int xStart, int xEnd) {
            this.y = y;
            this.type = type; // for y start or end, +1 for startpoint and -1 for endpoint
            this.xStart = xStart;
            this.xEnd = xEnd;
        }
    }

    public double separateSquares(int[][] squares) {
        List<Event> events = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for (int[] sq : squares) {
            int x = sq[0], y = sq[1], size = sq[2];
            events.add(new Event(y, 1, x, x + size));
            events.add(new Event(y + size, -1, x, x + size));
            set.add(x);
            set.add(x + size);
        }
        int n = set.size();
        int x[] = new int[n];
        int p = 0;
        for (int num : set) {
            x[p++] = num;
        }
        Arrays.sort(x);
        events.sort(Comparator.comparingDouble(e -> e.y));
        int coverCount[] = new int[4 * n]; // tree
        double coverLength[] = new double[4 * n]; // tree, x interval length
        double totalArea = 0;
        double prevY = events.get(0).y;
        List<double[]> parts = new ArrayList<>();
        int i = 0;
        while (i < events.size()) {
            double currY = events.get(i).y;
            if (currY > prevY) {
                double height = currY - prevY;
                double width = coverLength[1];
                totalArea += width * height;
                parts.add(new double[] { prevY, currY, width });
                prevY = currY;
            }
            while (i < events.size() && events.get(i).y == currY) {
                Event e = events.get(i);
                int left = Arrays.binarySearch(x, e.xStart);
                int right = Arrays.binarySearch(x, e.xEnd);
                updateTree(1, 0, n, left, right, e.type, x, coverCount, coverLength);
                i++;
            }
        }
        double half = totalArea / 2;
        double sum = 0;
        for (double part[] : parts) {
            double y1 = part[0], y2 = part[1];
            double width = part[2];
            double area = width * (y2 - y1);
            if (sum + area >= half) {
                return y1 + (half - sum) / width;
            }
            sum += area;
        }
        return prevY;
    }

    public void updateTree(int node, int start, int end, int left, int right, int value, int x[], int coverCount[],
            double coverLength[]) {
        if (right <= start || end <= left)
            return;
        if (left <= start && end <= right) {
            coverCount[node] += value;
        } else {
            int mid = (start + end) / 2;
            updateTree(node * 2, start, mid, left, right, value, x, coverCount, coverLength);
            updateTree(node * 2 + 1, mid, end, left, right, value, x, coverCount, coverLength);
        }
        if (coverCount[node] > 0) {
            coverLength[node] = x[end] - x[start];
        } else {
            if (end - start == 1) {
                coverLength[node] = 0;
            } else {
                coverLength[node] = coverLength[node * 2] + coverLength[node * 2 + 1];
            }
        }
    }
}
