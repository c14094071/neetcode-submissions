class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> subseq_sum;
        int sum=0,neg_sum =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                sum += nums[i];
                if(nums[i+1]<0 || i== nums.size()-1){
                    subseq_sum.push_back(sum);
                }
            }else {
                
                neg_sum += nums[i];
                subseq_sum.push_back(nums[i]);
                if(nums[i+1]>=0){
                    if((neg_sum + sum)>=0){
                        sum += neg_sum;
                        neg_sum = 0;
                    }else{
                        sum = 0;
                        neg_sum = 0;
                    }
                }

            }
            
        }

        auto result = max_element(subseq_sum.begin(),subseq_sum.end());
        return *result;
    }
};
