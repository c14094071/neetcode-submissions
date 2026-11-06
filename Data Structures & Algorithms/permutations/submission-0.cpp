class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> set;
        vector<int> visited(nums.size(),0);
        vector<vector<int>> ret;
        dfs(nums,set,visited,ret,0);
        return ret;
    }
    void dfs(vector<int>& nums,vector<int> set,vector<int> visited, vector<vector<int>>& ret,int level){
        if(level == nums.size()){
            ret.push_back(set);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==1) continue;
            set.push_back(nums[i]);
            visited[i]=1;
            dfs(nums,set,visited,ret,level+1);
            set.pop_back();
            visited[i]=0;
        }
    }
};
