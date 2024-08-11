#include <vector>

using namespace std;

class Solution {
    void rowala(vector<vector<int>>& mat, int n, int m, int i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] != 0) {
                mat[i][j] = -99999;  // Temporarily mark non-zero cells
            }
        }
    }

    void colwala(vector<vector<int>>& mat, int n, int m, int j) {
        for (int i = 0; i < n; ++i) {
            if (mat[i][j] != 0) {
                mat[i][j] = -99999;  // Temporarily mark non-zero cells
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // First pass to mark rows and columns
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    rowala(mat, n, m, i);
                    colwala(mat, n, m, j);
                }
            }
        }

        // Second pass to set zeroes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == -99999) {
                    mat[i][j] = 0;  // Convert marked cells to zero
                }
            }
        }
    }
};
