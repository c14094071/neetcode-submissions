class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> cars;
        vector<pair<int,int>> carpairs;
        for(int i=0;i<position.size();i++){
            carpairs.push_back(make_pair(position[i],speed[i]));
        }   
        sort(carpairs.begin(),carpairs.end());
        for(auto c:carpairs) cout<<c.first<<" "<<c.second<<endl;
        for(int i=carpairs.size()-1;i>=0;i--){
            
            if(!cars.empty()&& float(target-cars.top().first)/float(cars.top().second) >= float(target-carpairs[i].first)/float(carpairs[i].second)){
                continue;
            }
            cars.push(carpairs[i]);

        }
        return cars.size();
    }
};
