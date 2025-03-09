class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), left = 0, groups = 0;

        for (int right = 1; right < n + k - 1; right++) {
            if (colors[right % n] == colors[(right - 1) % n])
                left = right;
            if (right - left + 1 == k)
                groups++, left++;
        }

        return groups;

        // TLE ---->
        // int n = colors.size(), groups = 0;
        // for (int i = 0; i < n; i++) {
        //     bool check = true;
        //     for (int j = i; j < i + k - 1; j++) {
        //         if ((colors[(j + 1) % n] == 0 && colors[j % n] == 0) ||
        //             (colors[(j + 1) % n] == 1 && colors[j % n] == 1)) {
        //             check = false;
        //             break;
        //         }
        //     }
        //     if (check)
        //         groups++;
        // }
        // return groups;
    }
};
