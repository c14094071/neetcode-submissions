class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(!stk.empty()){
                if(stk.top() == '(' && s[i]==')') stk.pop();
                else if(stk.top() == '[' && s[i]==']') stk.pop();
                else if(stk.top() == '{' && s[i]=='}') stk.pop();
                else stk.push(s[i]);
            }else stk.push(s[i]);
        }
        if(stk.empty()) return true;
        return false;
    }
};
