class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indices;
        for(int i=nums.size(); i>= 0;i--){
            indices[nums[i]] = i; // only smaller index
        }
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(indices.count(diff) && indices[diff] != i){
                return{min(i ,indices[diff]),max(i ,indices[diff])};
            }
        }
        return {};
    }
};
