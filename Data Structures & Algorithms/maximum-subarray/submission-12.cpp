#define print(v) (cout << "line " << __LINE__ << ": " << #v << " = " << (v) << endl)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int r=0;
        int sum = 0;
        int maxsum = nums[0];
        while(r<nums.size()){
            
            if(sum<0){
                sum=0;
            }
            sum += nums[r];
            maxsum = max(maxsum, sum);

            r++;
        }
    
        return maxsum;
       
    }
};
