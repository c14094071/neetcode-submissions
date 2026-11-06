class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        count = n ##一開始有n個陣營 

        def find(parent,count,node):
            if(parent[node] != node): ##如果自己不是老大就往上找
                parent[node] = find(parent,count,parent[node]) ##將自己的老大編號都改成最高層的那個
            return parent[node] ##終於自己是老大


        def union(parent,x,y): ##找出兩個點的老大編號，並讓其中一方拜向另一方的老大
            nonlocal count ##因為integer不可變動(會copy一份到function)，注意nonlocal
            x_parent = find(parent,count,x) ##x最高層的老大
            y_parent = find(parent,count,y) ##y最高層的老大
            if(x_parent != y_parent):
                parent[x_parent] = y_parent
                count -= 1
        for node in edges:
            union(parent,node[0],node[1])
        return count

            
        