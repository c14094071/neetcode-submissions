class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            vector<int> triple;
            triple.push_back(nums[i]);
            int target = ~nums[i]+1;
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                if(nums[start]+nums[end]>target){
                    end--;
                }
                else if(nums[start]+nums[end]<target){
                    start++;
                }
                else {
                    triple.push_back(nums[start]);
                    triple.push_back(nums[end]);
                    ret.push_back(triple);
                    triple.resize(0);
                    triple.push_back(nums[i]);
                    start++;
                    end--;
                   
                    
                    
                }
            }
        }
        
        sort(ret.begin(),ret.end());
        auto last = std::unique(ret.begin(), ret.end());
        ret.erase(last,ret.end());
        return ret;
    }
};
