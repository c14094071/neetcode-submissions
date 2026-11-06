class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hash;
        
        for(int num:nums){
            hash[num]+=1;
        }
        vector<pair<int,int>> vec (hash.begin(),hash.end());
        
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ret;
        for(int i=0;i<k;i++){
            ret.push_back(vec[i].first);
        }
        return ret;
    }
};
