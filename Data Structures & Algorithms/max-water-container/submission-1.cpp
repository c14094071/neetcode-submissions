class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r=heights.size()-1;
        int area = (r-l)*min(heights[l],heights[r]);
        while(l<r){
            if(heights[l]>=heights[r]){
                r--;
            }
            else {
                l++;
            }
            area = max(area,(r-l)*min(heights[l],heights[r]));
        }
        return area;
        
    }
};
