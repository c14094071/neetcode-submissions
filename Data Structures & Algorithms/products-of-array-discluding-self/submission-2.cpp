class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total =1;
        vector<int> ret;
        ret.push_back(total);
        for(int i=0;i<=nums.size()-2;i++){
            total *= nums[i];
            ret.push_back(total);
        }
        total = 1;
        
        for(int i=nums.size()-1;i>0;i--){
            total *= nums[i];
            ret[i-1] *= total;
        }
        return ret;
    }
};
