class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        ## no circle and fully connected
        parent_list = [i for i in range(n)]
        count = n
        def find(node):
            if(node != parent_list[node]):
                parent_list[node] = find(parent_list[node])
            return parent_list[node]
        def union(x,y):
            nonlocal count
            parent_x = find(x)
            parent_y = find(y)
            if(parent_x == parent_y): ##兩個沒有直接連線的點有共同向上的父節點，此時連線則出現環
                return False
            else:
                parent_list[parent_x] = parent_y
                count-=1
        for u,v in edges:
            if union(u,v) == False:  # 接住警報！一旦發現環，立刻終止並回傳 False
                return False
        if(count!=1):
            return False
        return True
            

            
        