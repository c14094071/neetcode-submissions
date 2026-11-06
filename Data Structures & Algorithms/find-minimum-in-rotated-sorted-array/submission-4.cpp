class Solution {
public:
    int findMin(vector<int> &nums) {
        //能不能找到一個 f(i)，讓它在陣列上單調？
        // nums[i]4 5 6 7 0 1 2 
        //f(i)F F F F T T T
        int left = 0,right = nums.size()-1;
        while(left < right){
            // int mid = (left+right)/2; -> adding causes overflow
            int mid = left + (right-left)/2 ;
            
            if(nums[mid]<nums[right]) right = mid;
            else if(nums[mid]>nums[right]) left = mid +1;
            else return nums[mid];
        }
    }
};
