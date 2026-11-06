class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> umap,window;
        string temp_ret="";
        for(char c:t) umap[c]++;
        int l=0,r=0,flag=0;
        while(umap[s[l]]<0) l++;
        r= l+t.size()-1;
        for(int i=l;i<l+t.size();i++){
            temp_ret += s[i];
            window[s[i]]++;
        } 
        string ret= s+t;
        
        while(l<=r){
            flag=1;
            for(char c:t){
                if(umap[c]>window[c]) flag=0;
            }
            if(flag==1){
                
                if(temp_ret.size()<ret.size()){
                    ret = temp_ret;
                }
                window[s[l]]--;
                l++;
                temp_ret.erase(0,1);
            }
            else if(r<s.size()){
                r++;
                window[s[r]]++;
                temp_ret += s[r];
            }
            else break;
            
            
            cout<<temp_ret<<endl;
                
            
        }
        
        if(ret==(s+t)) return "";
        return ret;

    }
};
