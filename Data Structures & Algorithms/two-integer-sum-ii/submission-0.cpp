class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0,end = numbers.size()-1;
        vector<int> ret;
        while(start<end){
            if((numbers[start]+numbers[end])>target) end--;
            else if((numbers[start]+numbers[end])<target) start++;
            else {
                ret.push_back(start+1);
                ret.push_back(end+1);
                return ret;
            }
        }
        
    }
};
