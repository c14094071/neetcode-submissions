class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if( n==0 ){
            ret.push_back("");
            return ret;
        }
        recurse(ret,"","(",1,0,n);
        return ret;
        
    }
    
    void recurse(vector<string>& ret,string s,string add, int open, int close, int n){
        
        s+=add;
        if(open<n && close <n && !(close>open)){
            recurse(ret,s,"(",open+1,close,n);
            recurse(ret,s,")",open,close+1,n);
        }
        else if(open ==n && close<open){
            recurse(ret,s,")",open,close+1,n);
        }
        else if(open==n & close ==n){
            ret.push_back(s);
        }else{
            return;
        }
        
        
        
    }
};
