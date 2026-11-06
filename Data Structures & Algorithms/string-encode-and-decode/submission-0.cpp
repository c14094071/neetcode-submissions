class Solution {
public:

    string encode(vector<string>& strs) {
        string ret ="";
        for(auto str:strs){
            
            ret += to_string(str.size())+"#"+str;
        }
        
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int start=0;
        for(int i=0;s[i];i++){
            if (s[i]=='#'){
                
                string temp = s.substr(start,(i-start));
                
                int num = stoi(temp);
                ret.push_back(s.substr(i+1,num));
                start = i + num+1;
                i=i+num;
                
            }
        }
        return ret;
    }
};
