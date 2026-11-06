class Solution {
public:
    int trap(vector<int>& height) {
        int l=-1,r=height.size();
        int maxl=0,maxr=0;
        int total =0;
        while(l<r){
            if(maxl<=maxr){
                l++;
                
                if(maxl-height[l]>0) total += (maxl-height[l]);
                else maxl = height[l];
                
                
            }else{
                r--;
                cout<<maxr-height[r]<<endl;
                if(maxr-height[r]>0) total += (maxr-height[r]) ;
                else maxr = height[r];
                
            }
                
        }
        
        
        
        return total;
    }
};
