#define print(v) (cout << "line " << __LINE__ << ": " << #v << " = " << (v) << endl)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0;
        int r=0;
        int sum = 0;
        int maxsum = 0;
        while(r<nums.size()){
            
            if((sum+nums[r])<0){
                l = r+1;
                
                
                sum=0;
            }else{
                
                sum += nums[r];
                nums[r] = max(maxsum, sum);
                print(sum);
            }
            r++;
        }
        maxsum = *(max_element(nums.begin(),nums.end()));
        print(sum);
        return maxsum;
       
    }
};
