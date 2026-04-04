class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string result = "";
        for (int col = 0; col < cols; col++) {
            for (int i = col; i < n; i += (cols + 1)) {
                result += encodedText[i];
            }
        }

        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
