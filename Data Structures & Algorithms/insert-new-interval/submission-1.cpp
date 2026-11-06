class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        int l=0;
        int r = intervals.size()-1;
        while(l<intervals.size() && intervals[l][1]< newInterval[0] ){
            results.push_back(intervals[l]);
            l++;
        }
        while(r >= 0 && intervals[r][0]> newInterval[1] ){
            r--;
        }
        
        if(l<=r) {
            int start = min(newInterval[0], intervals[l][0]);
            int end   = max(newInterval[1], intervals[r][1]);
            results.push_back({start,end});
        }else results.push_back(newInterval);
        

        for(int i=r+1;i<intervals.size();i++){
            results.push_back(intervals[i]);
        
        }
        return results;
    }
};
