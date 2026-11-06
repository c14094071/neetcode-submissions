class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> umap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> vec = umap[key];
        int l=0,r=vec.size()-1;
        string ret = "";
        while(l<=r){
            int mid = l+(r-l)/2;
            if(vec[mid].second>timestamp){
                r= mid-1;
            }else if(vec[mid].second<=timestamp){
                l = mid+1;
                ret = vec[mid].first;
            }
        }
        return ret;
    }
};
