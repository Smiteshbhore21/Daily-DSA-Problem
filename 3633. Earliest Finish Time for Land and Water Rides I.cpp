class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int bestLandFinish = INT_MAX;
        int bestWaterFinish = INT_MAX;

        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            bestLandFinish =
                min(bestLandFinish, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            int curr =
                max(bestLandFinish, waterStartTime[i]) + waterDuration[i];
            ans = min(ans, curr);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            bestWaterFinish =
                min(bestWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            int curr =
                max(bestWaterFinish, landStartTime[i]) + landDuration[i];
            ans = min(ans, curr);
        }

        return ans; 
    }
};
