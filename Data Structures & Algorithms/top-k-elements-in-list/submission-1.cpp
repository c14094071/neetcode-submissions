class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> up;
        for (auto num: nums){
            up[num]++;
        }
        vector<std::pair<int,int>> res;
        // 使用引用 & 避免拷贝开销，若只需读取可加 const
        for (auto const& [key, val] : up){
            res.push_back(std::make_pair(key,val));
        }
        sort(res.begin(),res.end(),[](const std::pair<int,int>&a, const std::pair<int,int>&b){ return a.second>b.second;} );
        vector<int> result;
        for(auto item: res){
            result.push_back(item.first);
            k--;
            if(k==0) break;
        }
        return result;
        
    }
};
