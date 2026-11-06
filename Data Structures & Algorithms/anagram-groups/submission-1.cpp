class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> umap;
        for (int i = 0;i < strs.size() ;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            umap[temp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto val : umap){
            result.push_back(val.second);
        }
        return result;


    }
};
