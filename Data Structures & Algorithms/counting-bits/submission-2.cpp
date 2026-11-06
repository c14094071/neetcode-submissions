class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        
        for(int i=0;i<=n;i++){
        
            int num = i;
            while(num>0){
                
                num = num & (num-1);
                res[i]++;
            }
            
        }
        return res;
    }
};
