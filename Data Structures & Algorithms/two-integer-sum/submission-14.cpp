class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> res;
        vector<pair<int,int>> pair_nums;
        for(int i=0;i<nums.size();i++) pair_nums.push_back(std::make_pair(nums[i],i));
        std::sort(pair_nums.begin(),pair_nums.end());
        while(i<j){
            int temp = pair_nums[i].first+pair_nums[j].first;
            if(temp>target){
                j--;
            }else if(temp==target){
                res.push_back(min(pair_nums[i].second,pair_nums[j].second));
                res.push_back(max(pair_nums[i].second,pair_nums[j].second));
                return res;
            }
            else if(temp<target){
                i++;
            }
        }
        return res;
    }
};
