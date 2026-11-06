class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int start=0;
        set<char> set;
        
        for(char c:s){
            if(set.count(c)>0){
                maxlen = max(maxlen,int(set.size()));
                while(set.count(c)>0){
                    set.erase(set.find(s[start]));
                    start++;
                }
            } 
            set.insert(c);

        }
        maxlen = max(maxlen,int(set.size()));
        return maxlen;
    }
};
