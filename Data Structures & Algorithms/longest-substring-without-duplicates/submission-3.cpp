class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;

        unordered_set<char> uset;
        queue<char> fifo;
        for(char c:s){
            if(uset.count(c)>0){
                maxlen = max(maxlen,int(fifo.size()));
                while(fifo.front()!=c){
                    char pop_c = fifo.front();
                    fifo.pop();
                    uset.erase(pop_c);
                }
                char pop_c = fifo.front();
                fifo.pop();
                uset.erase(pop_c);
              
            }
         
            uset.insert(c);
            fifo.push(c);
        }
        maxlen = max(maxlen,int(fifo.size()));
        return maxlen;
    }
};
