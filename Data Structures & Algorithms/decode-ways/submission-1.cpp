class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size(),0);
        // s : 13421
        // pick up last one : all combination of prev "1342"  -> dp[i-1]
        // pick up last two : all comb. of prev "134" -> dp[i-2]
        // s : 13420
        // could not pick up last one
        // pick up last tow : all comb. of prev "134"
        if(s[0] == '0') return 0;
        else dp[0] = 1; 
        for(int i=1; i<s.size();i++){
            
            if(s[i] != '0'){
            // pick up last one
                dp[i] += dp[i-1]; //ex: "1320" 5 , "1325" 0, "5" 0
                
            }
            // pick up last two
            string two = s.substr(i-1,2);
            int num = stoi(two);
            if(num >=10 && num <=26){
                if(i==1){
                    dp[i] += 1; // ex : "50"
                }else {
                    dp[i] += dp[i-2]; // ex : "132" 50, "132" 05 
                }
                
            }
            
        }
        return dp[s.size()-1];
    }
};
