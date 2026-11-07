class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int w = heights[0].size();
        int l = heights.size();
        vector<vector<bool>> peaks_ul(l,vector<bool>(w,false));
        vector<vector<bool>> peaks_lr(l,vector<bool>(w,false));
        vector<vector<int>> results;
        
        
        for(int i=0;i< w;i++){
            dfs(heights,peaks_ul,INT_MIN,0,i);
            dfs(heights,peaks_lr,INT_MIN,l-1,i);
        }
        for(int i=0;i< l;i++){
            dfs(heights,peaks_ul,INT_MIN,i,0);
            dfs(heights,peaks_lr,INT_MIN,i,w-1);
        }
     
        for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (peaks_ul[i][j] && peaks_lr[i][j]) {
                results.push_back({i, j});
                }
            }
        }
        return results;
        
        
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,int prev_val, int row, int col){
        if(row < 0 || row > heights.size()-1 || col <0 || col > heights[0].size()-1){
            return;
        }
        if(heights[row][col] <prev_val ){
            return;
        }
        if(visited[row][col]){
            return;
        }
        visited[row][col] = true;
        
        dfs(heights,visited,heights[row][col],row-1,col);
        dfs(heights,visited,heights[row][col],row,col-1);
        dfs(heights,visited,heights[row][col],row+1,col);
        dfs(heights,visited,heights[row][col],row,col+1);

    }
};
