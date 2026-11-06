class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map <string, vector<string>> hash;
        for (string str:strs){
            string temp = str;
            sort(str.begin(),str.end());
            hash[str].push_back(temp);
        }
        for(auto pair : hash){
            ret.push_back(pair.second);
        }
        
        return ret;
    }
};
