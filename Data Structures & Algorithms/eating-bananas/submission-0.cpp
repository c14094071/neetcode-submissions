class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *std::max_element(piles.begin(),piles.end());
        int l=1,r=max;
        int min_b=INT_MAX;
        while(l<=r){
            int mid = l+ (r-l)/2;
            int times = 0;
            cout<<mid<<endl;
            for(auto b:piles) times += ceil(float(b)/mid); //no (b/mid+1)
            
            if(times>h) l = mid+1;
            else if(times<h){
                r= mid-1;
                min_b = min(min_b,mid);
            } 
            else return mid;
            
        }
        return min_b;
    }
};
