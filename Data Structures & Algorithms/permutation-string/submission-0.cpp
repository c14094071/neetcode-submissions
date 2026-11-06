class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> umap,window;
        if(s1.size()>s2.size()) return false;
        for(char c: s1) umap[c]++;
        for(int i=0;i<s1.size();i++) window[s2[i]]++;
        int matches=0;
        for(int c = 'a';c<='z';c++){
            if(umap[char(c)]==window[char(c)]){
                matches++;
            }
            
        }
        if(matches==26) return true;
        
        int l=0;
        for(int i=s1.size();i<s2.size();i++,l++){
            window[s2[l]]--;
            window[s2[i]]++;
            
            
            matches=0;
            for(int c = 'a';c<='z';c++){
                if(umap[char(c)]==window[char(c)]){
                    matches++;
                }
                
            }
            if(matches==26) return true;
       
            cout<<endl;
        }
        return false;
    }
};
