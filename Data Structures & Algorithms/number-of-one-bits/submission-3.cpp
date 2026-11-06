class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;
        while(n>0){
            n&= n-1;//將最右邊的1移到最低位並消除
            count++;
        }
        return count;
    }
};
