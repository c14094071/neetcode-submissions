class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r=heights.size()-1;
        
        int best_l=0,best_r=heights.size()-1;
        int area = (r-l)*min(heights[best_l],heights[best_r]);
        while(l<r){
            if(heights[best_l]>=heights[best_r]){
                
                while(best_l<r){
                    if(heights[r]>heights[best_r]){
                        best_r = r;
                        break;
                    }
                    r--;
                } 
                
            }
            else if(heights[best_l]<heights[best_r]){
                
                while(l<best_r){
                    if(heights[l]>heights[best_l]){
                        best_l = l;
                        break;
                    }
                    l++;
                } 
                
                
            }
            area = max(area,(r-l)*min(heights[best_l],heights[best_r]));
        }
        return area;
        
    }
};
