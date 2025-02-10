class Solution {
public:
    string clearDigits(string s) {
      //O(n^2) ->
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] >= 48 && s[i] <= 57) {
        //         s.erase(i - 1, 2);  ----> Worst Case O(n)
        //         i -= 2;
        //     }
        // }
        // return s;

      //O(n) ->
      string ans = "";
        for (const auto& c : s) {
            if (c >= 48 && c<=57) 
                ans.pop_back();
             else
                ans.push_back(c);
        }
        return ans;
    }
};
