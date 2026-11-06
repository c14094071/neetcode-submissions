class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total =1;
        int zero_count =0;
        for(auto num : nums){
            
            if( num == 0){
                zero_count++;
                continue;
            }
            
            total *= num;
        }
        if(zero_count == 1){
            for(int i=0;i<nums.size();i++){
                nums[i] = nums[i] ==0 ? total :0;
                
            }
        }
        else if(zero_count > 1){
            for(int i=0;i<nums.size();i++){
                nums[i] = 0;
                
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                nums[i] = total/nums[i];
            }
        }
        return nums;
    }
};
