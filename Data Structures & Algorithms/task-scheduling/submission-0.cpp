class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> counts;
        for(auto c:tasks){
            counts[c]++;
        }
        priority_queue<int> maxheap;
        for(auto count:counts){
            maxheap.push(count.second);
            
        }
        int time=0;
        int cycles=0;
        deque<pair<int,int>> dq;
        
        while(!maxheap.empty()||!dq.empty()){
            time++;
            //避免dq pop出來的東西無法在該時間使用且延到下個時間點，因此將此行為提前
            if(!dq.empty()){
                pair<int,int> dqFront = dq.front();
                if(dqFront.second<=time){
                    dq.pop_front();
                    maxheap.push(dqFront.first);
                }
            }
            if(!maxheap.empty()){
                int tp = maxheap.top();
                tp--;
                maxheap.pop();
                //time=1、n=2時，則下一次最快使用的時間則是time =4，因為間隔2
                if(tp>0) dq.push_back(make_pair(tp,1+time+n));
            }
            
            
            
        }
        
        return time;

    }
};
