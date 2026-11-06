class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq.reserve(k);
        for(int num:nums) freq[num]++;

        int n = nums.size();
        vector<vector<int>> buckets (n+1);
        for(const auto& [num,cnt] : freq){
            buckets[cnt].push_back(num);
        }
        vector<int> result;
        result.reserve(k);
        for(int cnt = n; cnt >=1 && result.size()<k;cnt--){
            for(int num :buckets[cnt]){
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};
