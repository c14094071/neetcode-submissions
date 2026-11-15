class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //a sequence of dictionary words：每個切出來的單字都必須存在字典中，但不要求使用全部單字。
        //a sequence containing all dictionary words：才會要求所有字典單字都必須出現。
        int n = s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); //copy dict vector to dict umap
        

        dp[0] = true;
        for(int i=1;i<=n;i++){ //取前i個長度的子字串
            for(int j=0;j<i;j++){ // 子字串的初始到最後的位置
                string word = s.substr(j,i-j);//子字串根據j不同的位置開始往後到最後一個字元切word
                
                if(dp[j] && dict.count(word)){
                    //dp[j] == true：前面所有字元已經可以完整切分。
                    //dict.count(word)：最後這一段也是字典中的單字。
                   dp[i] = true;
                   break;
                }
            }
        }
        return dp[n];
    }
};
