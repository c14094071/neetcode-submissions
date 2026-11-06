class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        amount_list = [amount+1]*(amount+1)
        amount_list[0] = 0
        for i in range(amount+1):
            for coin in coins:
                if(i-coin>=0):
                    amount_list[i] = min(amount_list[i-coin]+1,amount_list[i])
        if(amount_list[-1]==amount+1):
            return -1
        return amount_list[-1]
            
            

        