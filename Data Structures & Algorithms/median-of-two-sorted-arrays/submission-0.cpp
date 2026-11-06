class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int half = (total)/2;
        if(nums2.size()<nums1.size()){
            swap(nums1,nums2);
        }
        int l = 0;
        int r = nums1.size()-1;
        //int count=0;
        while(true){
            //count++;
            int mid1 = l+floor(float(r-l)/2);
            int mid2 = half - (mid1+1)-1;
       
            int left1 = mid1==-1?INT_MIN:nums1[mid1];
            int n=nums1.size();
            int right1 = mid1+1>=n? INT_MAX:nums1[mid1+1];
            cout<<mid1<<endl;
            cout<<left1<<" "<<right1<<endl;
            int left2 = mid2==-1?INT_MIN:nums2[mid2];
            int m = nums2.size();//需先將size_t轉成int再比較
            int right2 = mid2+1 >= m ? INT_MAX:nums2[mid2+1];
            //int right2 = mid2 >=nums2.size()? INT_MAX:nums2[mid2+1];
            cout<<mid2<<endl;
            //cout<<(mid2 >=(nums2.size()))<< endl;
            cout<<left2<<" "<<right2<<endl;
            if(left1<=right2 && left2<=right1){
                return total%2==1? min(right1,right2): float(max(left1,left2)+min(right1,right2))/2;
            } else if(left1>left2){
                r = mid1-1;
            } else {
                l = mid1+1;
            }
        }
        return -1;
    }
};
