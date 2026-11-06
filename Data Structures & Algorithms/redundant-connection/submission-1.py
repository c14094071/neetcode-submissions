class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent_list = {}
        count = 0
        def find(node):
            nonlocal count
            if node not in parent_list:
                parent_list[node]=node
                count +=1
            if(parent_list[node] != node):
                parent_list[node] = find(parent_list[node])
            return parent_list[node] ## 別在寫在if裡面
        def union(x,y):
            nonlocal count
            parent_x = find(x)
            parent_y = find(y)
            if(parent_x == parent_y):
                return True
            if(parent_x != parent_y):
                parent_list[parent_x] = parent_y
                count -= 1
            return False
        for u,v in edges:    
            if(union(u,v)):
                return [u,v]
        return []
            

        

            