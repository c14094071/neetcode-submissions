class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        stack<string> temp;
        for(int i=tokens.size()-1;i>=0;i--) st.push(tokens[i]);
        while(!st.empty()){
            string op = st.top();
            if(op=="+"){
                st.pop();
                int b = stoi(temp.top());
                temp.pop();
                int a = stoi(temp.top());
                temp.pop();
                temp.push(to_string(a+b));

            }
                
            else if(op=="-"){
                st.pop();
                int b = stoi(temp.top());
                temp.pop();
                int a = stoi(temp.top());
                temp.pop();
                temp.push(to_string(a-b));
            }
            else if(op=="/"){
                st.pop();
                int b = stoi(temp.top());
                temp.pop();
                int a = stoi(temp.top());
                temp.pop();
                temp.push(to_string(a/b));
            }
            else if(op=="*"){
                st.pop();
                int b = stoi(temp.top());
                temp.pop();
                int a = stoi(temp.top());
                temp.pop();
                temp.push(to_string(a*b));
            }
            else{
                
                temp.push(st.top());
                st.pop();
                
            }
            
        }
        return (stoi(temp.top()));
    }
};
