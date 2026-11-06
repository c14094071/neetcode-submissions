class Solution {
public:
    bool isPalindrome(string s) {
        int head=0,tail = s.length() - 1;
        while(head<tail){
            while(head<tail && !('A'<= s[head] && s[head] <= 'Z') && !('a'<= s[head] && s[head]<= 'z')&& !('0'<= s[head] && s[head]<= '9')) {
                head++;
            }
            while(head < tail && !isalnum(s[tail])) {
                tail--;
            }
            if(tolower(s[head])!=tolower(s[tail])){
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};
