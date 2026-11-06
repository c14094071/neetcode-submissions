class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> set;
        vector<vector<int>> ret;
        comb(nums,target,set,ret,0);
        return ret;
    }
    void comb(vector<int>& nums, int target, vector<int> set,vector<vector<int>>& ret, int index){
        if(target==0){
            ret.push_back(set);
            return;
        }else if(target<0){
            return;
        }
        for(int i=index;i<nums.size();i++){
            set.push_back(nums[i]);
            comb(nums,target-nums[i],set,ret,i);
            set.pop_back();
            
        }

    }
};
