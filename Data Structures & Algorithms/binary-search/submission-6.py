class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums.sort()
        l=0
        r = len(nums)-1
        mid = (r-l)//2
        
        while(l>=0 and r<= len(nums)-1 and l<=r):
            if(nums[mid]<target):
                l = mid + 1
            elif(nums[mid]>target):
                r = mid -1 
            else: return mid
            mid = l+(r-l)//2
        return -1

        