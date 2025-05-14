class Solution {
    using Matrix = array<array<int, 26>, 26>;
    int M = 1e9 + 7;

    inline Matrix matrixMultiplication(Matrix& A, Matrix& B) {
        Matrix res{};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    res[i][j] = (res[i][j] + (1ll * A[i][k] * B[k][j]) % M) % M;
                }
            }
        }
        return res;
    }

    inline Matrix matrixExpo(Matrix& transformation_matrix, int t) {
        Matrix res{};
        for (int i = 0; i < 26; i++) {
            res[i][i] = 1;
        }
        while (t) {
            if (t & 1)
                res = matrixMultiplication(transformation_matrix, res);
            transformation_matrix = matrixMultiplication(transformation_matrix,
                                                         transformation_matrix);
            t /= 2;
        }
        return res;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        array<int, 26> initial_freq{};
        Matrix tranformation_matrix{};
        for (char c : s)
            initial_freq[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j <= i + nums[i]; j++) {
                tranformation_matrix[j % 26][i]++;
            }
        }
        Matrix res = matrixExpo(tranformation_matrix, t);
        array<int, 26> final_array{};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                final_array[i] =
                    (final_array[i] + (1ll * res[i][j] * initial_freq[j]) % M) %
                    M;
            }
        }
        int string_size = 0;
        for (int i = 0; i < 26; i++) {
            string_size = (string_size + final_array[i]) % M;
        }
        return string_size;
    }
};
