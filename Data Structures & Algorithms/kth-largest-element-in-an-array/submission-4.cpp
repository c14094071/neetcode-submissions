class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k+1; //第k大 -> 第len-k+1小
        return quickselect(nums,0,nums.size()-1,k);
    }
    int quickselect(vector<int>& nums,int l,int r,int k){
        int pivot = nums[r];
        int i = l;
        for(int j=l;j<r;j++){
            if(nums[j]<=pivot){
                std::swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        // k-1 因為i從0開始 而k則是從1開始算
        if(i>k-1) return quickselect(nums,l,i-1,k);
        else if (i<k-1) return quickselect(nums,i+1,r,k);
        else if (i==k-1) return nums[i];

        
    }
};
