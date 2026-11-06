class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> umap1,umap2;
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            umap1[s[i]]++;
            umap2[t[i]]++;
        }
        for(auto &m : umap1){
            char c= m.first;
            if(umap1[c] != umap2[c]){
                return false;
            }
        }
        return true;
    }
};
