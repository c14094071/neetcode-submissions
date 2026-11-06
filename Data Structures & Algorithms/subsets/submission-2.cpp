class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> results;
        dfs(0, temp,nums,results);
        
        return results;
    }
    void dfs(int start,vector<int> temp, vector<int>& nums,vector<vector<int>> & results){
        results.push_back(temp);
        for(int i = start;i<nums.size();i++){
            //1.做選擇
            temp.push_back(nums[i]);
            //2.遞迴
            dfs(i+1,temp,nums,results);
            //3.撤銷選擇
            temp.pop_back();

        }
    }
};
