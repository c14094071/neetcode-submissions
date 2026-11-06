class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        int l=0,r=0;
        while(r<nums.size()){
            
            while(!dq.empty()&&nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(dq.front()<l){
                dq.pop_front();
            }
            if(r>=k-1){
                ret.push_back(nums[dq.front()]);
                l++;
            }
            r++;

        }
        return ret;
    }
};
