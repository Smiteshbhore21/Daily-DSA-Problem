class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        for (int& asteroid : asteroids) {
            
            if(mass < asteroid){
                return false;
            }

            mass += asteroid;
            asteroid = 0;
        }

        return asteroids.back() == 0;
    }
};
