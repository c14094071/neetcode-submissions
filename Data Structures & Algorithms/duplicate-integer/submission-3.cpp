#include <array>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.find(num) != nullptr)
                return true;
            seen.insert(num);
        }
        return false;
        
        
        
    }
};