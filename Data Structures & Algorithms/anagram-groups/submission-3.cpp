class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> umap;
        
        for(const string &s : strs){
            vector<int> characters(26,0);
            for(const char c : s){
                characters[c-'a']++;
            }
            string key = "";
            for(int i =0; i < 26;i++){
                key += ','+to_string(characters[i]);
            }
            umap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& pair: umap){
            result.push_back(pair.second);
        }
        return result;


    }
};
