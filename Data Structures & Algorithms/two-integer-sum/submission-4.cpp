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
                result.push_back(pair_nums[i].second);
                result.push_back(pair_nums[j].second);
                sort(result.begin(),result.end());
                return result;
            }
            else if((pair_nums[i].first + pair_nums[j].first) > target){
                j--;
            }
            else i++;

        }
        return result;
    }
};
