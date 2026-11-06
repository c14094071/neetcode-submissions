class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(ret,nums,subset,0);
        return ret;

    }
    void dfs(vector<vector<int>>& ret, vector<int> nums, vector<int> subset ,int index ){
        if(index== nums.size()){
            ret.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(ret,nums,subset,index+1);
        subset.pop_back();
        while(index+1<nums.size()&& nums[index]==nums[index+1]) index+=1;
        dfs(ret,nums,subset,index+1);
        
        
        
    }
};
