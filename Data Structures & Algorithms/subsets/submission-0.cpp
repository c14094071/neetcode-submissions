class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        vector<vector<int>> ret;
        dfs(nums,0,set,ret);
        return ret;
    }
    void dfs(vector<int>& nums,int index,vector<int> set,vector<vector<int>>& allsubs){
        if(index<nums.size()){
            dfs(nums,index+1,set,allsubs);
            set.push_back(nums[index]);
            dfs(nums,index+1,set,allsubs);
        }else{
            allsubs.push_back(set);
        }
        
    }
};
