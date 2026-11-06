class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n);
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        } 
        result[0] = 1;
        result[1] = 2;
        
        for(int i=2; i< n; i++){
            
            result[i] = result[i-1] + result[i-2];
        }
        return result[n-1];
    }
};
