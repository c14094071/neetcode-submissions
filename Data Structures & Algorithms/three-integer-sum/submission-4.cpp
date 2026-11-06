class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
             // Skip the same element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
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
                    // Skip the same elements to avoid duplicate triplets
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;

                    triple.push_back(nums[i]);
                    start++;
                    end--;
                   
                    
                    
                }
            }
        }
        
        
        return ret;
    }
};
