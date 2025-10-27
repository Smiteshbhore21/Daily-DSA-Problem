class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevBeam = 0;
        int totalBeams = 0;
        for (const string& s : bank) {
            int currBeam = 0;
            for (const char& ch : s) {
                if (ch == '1')
                    currBeam++;
            }
            totalBeams += (prevBeam * currBeam);
            if (currBeam != 0)
                prevBeam = currBeam;
        }
        return totalBeams;
    }
};
