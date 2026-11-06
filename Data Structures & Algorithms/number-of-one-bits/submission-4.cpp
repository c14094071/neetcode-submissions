class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;
        while(n>0){
            //將最右邊的1變成0，並將其後的0都變成1,1100 -> 1011
            n&= n-1;//將最右邊的1移到最低位並消除
            count++;
        }
        return count;
    }
};
