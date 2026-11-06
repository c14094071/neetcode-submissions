class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i =0,j=nums.size()-1;
        vector<pair<int,int>> pair_nums;
        for(int i =0;i<nums.size();i++){
            pair_nums.push_back({nums[i],i});
        }
        sort(pair_nums.begin(),pair_nums.end());

        vector<int> result;
        while(i!=j){
            if((pair_nums[i].first + pair_nums[j].first) == target){
                
                
                return {min(pair_nums[i].second,pair_nums[j].second),
                max(pair_nums[i].second,pair_nums[j].second)};
            }
            else if((pair_nums[i].first + pair_nums[j].first) > target){
                j--;
            }
            else i++;

        }
        return result;
    }
};
