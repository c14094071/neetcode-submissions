class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int mid =0;
        int count =0;
        while(l<=r){
            if(nums[l]<nums[r]) return nums[l];
            mid = l+(r-l)/2;
            cout<< mid<<":"<<l<<","<<r<<endl;
            if(nums[mid]>=nums[l]) l = mid+1;//
            else if(nums[mid]<nums[l]) r= mid-1;
            if(nums[mid-1]>nums[mid]) break;
            
        }
        return nums[mid];
    }
};
