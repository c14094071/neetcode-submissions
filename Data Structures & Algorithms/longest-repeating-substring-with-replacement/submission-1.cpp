class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0,r=0;
        unordered_map<char,int> umap;
        int window_len=r-l+1;
        int maxlen = 0;
        umap[s[r]]++;
        while(l<=r && r<s.size()){
            int mostfreq = 0;
            for(auto p:umap){
                if(p.second>mostfreq) mostfreq = p.second;
            }
            window_len = r-l+1;
            cout<<window_len<<"-"<<mostfreq<<"="<<window_len-mostfreq<<endl;
            if(window_len-mostfreq<=k){
                
                maxlen = max(maxlen,window_len);
                r++;
                umap[s[r]]++;
                
            }else {
                umap[s[l]]--;
                l++;
                
                
            }
        }
        return maxlen;
    }
};
