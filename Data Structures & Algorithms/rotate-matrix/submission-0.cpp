class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix[0].size();
        vector<vector<int>> temp_matrix(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp_matrix[j][n-i-1] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = temp_matrix[i][j];
            }
        }
    }
};
