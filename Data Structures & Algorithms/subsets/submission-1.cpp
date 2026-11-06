class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> results;
        findsubset(0, true, temp,nums,results);
        findsubset(0, false, temp,nums,results);
        return results;
    }
    void findsubset(int index, bool chosen,vector<int> temp, vector<int>& nums,vector<vector<int>> & results){
        
        if(chosen == true) temp.push_back(nums[index]);
        else if(chosen == false) {};
        if(index==nums.size()-1){
            results.push_back(temp);
            return;
        } 
        findsubset(index+1,true,temp,nums,results);
        findsubset(index+1,false,temp,nums,results);
    }
};
