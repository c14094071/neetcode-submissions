class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> hash;
    list<pair<int,int>> lru;
    int maxSize;
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        auto findkey = hash.find(key);
        if(findkey!=hash.end()){
            int ret = (*(findkey->second)).second;
            lru.erase(findkey->second);
            lru.push_back(make_pair(key,ret));
            findkey->second = (--lru.end());
            //不可使用(lru.end()--)。括號會確保裡面的式子優先執行，如lru.end()--
            //但是後--會必定返回原本值，因此有無括號並無差別，並不會因為有括號而返回減後的值，不要被誤導了。
            return ret;  
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto findkey = hash.find(key);
        if(findkey!=hash.end()){
            lru.erase(findkey->second);
            lru.push_back(make_pair(key,value));
            findkey->second = (--lru.end());

        }else{
            if(lru.size()<maxSize){
                lru.push_back(make_pair(key,value));
                hash[key] = (--lru.end());
                
            }else{
                auto front = lru.front();
                hash.erase(front.first);
                lru.pop_front();
                lru.push_back(make_pair(key,value));
                hash[key] = (--lru.end());


            }
        }
    }
};
