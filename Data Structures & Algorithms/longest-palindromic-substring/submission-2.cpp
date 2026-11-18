class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0,maxlen = 1;
        
        string res;
        
        for(int mid=0;mid <n;mid++){
            int left = mid;
            int right = mid+1;
            while(left >= 0 && right <= n-1){
                if(s[left] == s[right]){

                    if(right-left+1> maxlen){
                        maxlen = right-left+1;
                        start = left;
                    }
                }else break;
                left--;
                right++;
            }
            left = mid;
            right = mid+2;
            while(left >= 0 && right <= n-1){
                if(s[left] == s[right]){
                    if(right-left+1> maxlen){
                        maxlen = right-left+1;
                        start = left;
                    }
                }else break;
                left--;
                right++;
            }
        }
        res = s.substr(start, maxlen);
        return res;
        
        
        
    }
};
