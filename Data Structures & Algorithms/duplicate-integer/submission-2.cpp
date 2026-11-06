#include <array>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        
        for(int i =0,j=1; j<nums.size();i++,j++){
            if(nums[i]== nums[j]){
                return true;
                
            }
        }
        return false;
    }
};