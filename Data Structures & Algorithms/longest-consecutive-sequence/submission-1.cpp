class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int longlen=0;
        for(auto num :nums){
            uset.insert(num);
        }
        for(auto num:nums){
            if(uset.count(num-1)>0){

            }else{
                int len=1;
                int next = num+1;
                while(uset.count(next)>0){
                    uset.erase(uset.find(next));
                    next++;
                    len++;
                }
                longlen = max(len,longlen);
            }
        }
        return longlen;
    }
};
