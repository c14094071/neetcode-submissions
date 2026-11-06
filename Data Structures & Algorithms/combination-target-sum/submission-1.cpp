class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> path;
        std::sort(nums.begin(),nums.end());
        dfs(results,nums,0,path, target);
        return results;
    }
    void dfs(vector<vector<int>>& results,vector<int>& nums,int index, vector<int>& path,int remain){
        if(remain == 0){
            results.push_back(path);
            return;
        }
        if(remain < 0){
            return;
        }
        if(index == nums.size()){
            return;
        }
        
        path.push_back(nums[index]);
        dfs(results,nums, index,path,remain-nums[index]);
        path.pop_back();
        dfs(results, nums, index+1,path, remain);
        
    }
};
