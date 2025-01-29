class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> minDis(numCourses,
                                    vector<bool>(numCourses, false));

        for (int i = 0; i < prerequisites.size(); i++)
            minDis[prerequisites[i][0]][prerequisites[i][1]] = true;

        for (int k = 0; k < numCourses; k++) {
          //Via
            for (int s = 0; s < numCourses; s++) {
              //Source
                for (int d = 0; d < numCourses; d++) {
                  //Destination
                    //If paths exist TRUE or FALSE
                    minDis[s][d] =
                        minDis[s][d] || (minDis[s][k] && minDis[k][d]);
                }
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++)
            ans.push_back(minDis[queries[i][0]][queries[i][1]]);

        return ans;
    }
};
