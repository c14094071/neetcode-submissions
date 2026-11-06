class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int mid =0;
        int count =0;
        int m = INT_MAX;
        while(l<=r){
            mid = l+(r-l)/2;
            
            cout<< mid<<":"<<l<<","<<r<<endl;
            if(nums[mid]>nums[r]) l = mid+1;
            else if(nums[mid]<nums[r]) r= mid;
            else return nums[l];

        }
        return nums[l];
    }
};
