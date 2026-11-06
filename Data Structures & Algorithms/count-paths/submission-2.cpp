class Solution {
public:
    int uniquePaths(int m, int n) {
        int max_num = max(m,n)-1;
        int min_num = min(m,n)-1;
        long long int total = 1;
        int j=1;
        for(int i = max_num+1;i<=max_num+min_num;i++){
            total = total*i;
            while(total%j==0 && j<=min_num){
                total /= j;
                j++;
            }
        }
        
        return total;

    }
};
