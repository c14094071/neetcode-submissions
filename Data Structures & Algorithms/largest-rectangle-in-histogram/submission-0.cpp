class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int max_area=0;
        for(int i=0;i<heights.size();i++){
            
            int index =i;
            while(!st.empty() && heights[i]< st.top().second){
                max_area = max(max_area,st.top().second*(i-st.top().first));
                index = st.top().first;
                st.pop();
                
            }
            st.push(make_pair(index,heights[i]));
        }
        if(!st.empty()){
            int final_index = st.top().first+1;
            
            while(!st.empty()){
                max_area = max(max_area, (final_index - st.top().first)*st.top().second);
                st.pop();
            }
        }
        return max_area;
    }
};
