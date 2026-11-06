class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
       
        return max(robbing(nums,0,nums.size()-2),robbing(nums,1,nums.size()-1));
    }
    int robbing(vector<int>& nums, int start, int end){
        int prev1 = nums[start+1];
        int prev2 = nums[start];
        if(start == end) return prev2;
        prev1 = max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
};
