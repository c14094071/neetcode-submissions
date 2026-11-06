class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int len = row * col - 1;
        int l = 0, r = len;
        while(l<=r  ){
            int mid = l+(r-l)/2;
            int value = matrix[mid/col][mid%col]; //mid/col not row
            if(value<target){
                l = mid+1;
            }
            else if(value>target){
                r = mid-1;
            }
            else if(value==target){
                return true;
            }
            
        }
        return false;
    }
};
