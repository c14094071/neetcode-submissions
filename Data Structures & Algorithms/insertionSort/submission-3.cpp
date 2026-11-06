// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        for(int i=0;i<pairs.size();i++){
            Pair temp(pairs[i].key,pairs[i].value);
            int j = i;
            for(j;j>0;j--){
                if(temp.key<pairs[j-1].key){
                    pairs[j] = pairs[j-1];
                    
                }
                else break;
            }
            if((pairs[j].key==pairs[j+1].key) && (pairs[j].value == pairs[j+1].value)){
                pairs[j] = temp;
            }
            
            res.push_back(pairs);
        }
        return res;
    }
};
