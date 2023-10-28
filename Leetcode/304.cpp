class NumMatrix {
private:
    vector<vector<int>> rsq2d;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        rsq2d = vector<vector<int>>(rows + 1, vector<int>(columns + 1, 0));
        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= columns; j++)
                rsq2d[i][j] = matrix[i - 1][j - 1] + 
                    rsq2d[i - 1][j] + rsq2d[i][j - 1] - rsq2d[i - 1][j - 1];
        }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return rsq2d[row2 + 1][col2 + 1] - rsq2d[row1][col2 + 1]
            - rsq2d[row2 + 1][col1] + rsq2d[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
