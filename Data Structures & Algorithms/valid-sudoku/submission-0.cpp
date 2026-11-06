class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows (board.size(),vector<int>{});
        vector<vector<int>> cols (board.size(),vector<int>{});
        vector<vector<int>> blocks (board.size(),vector<int>{});
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '1';
                
                
                vector<int>::iterator row_it = find(rows[i].begin(),rows[i].end(),num);
                vector<int>::iterator col_it = find(cols[j].begin(),cols[j].end(),num);
                
                vector<int>::iterator block_it = find(blocks[(i/3)*3+(j/3)].begin(),blocks[(i/3)*3+(j/3)].end(),num);
                
                if(row_it!=rows[i].end() || col_it != cols[j].end() || block_it != blocks[(i/3)*3+(j/3)].end()) return false;
                rows[i].push_back(num);
                cols[j].push_back(num);
                blocks[(i/3)*3+(j/3)].push_back(num);

            }
        }
        return true;
    }
};
