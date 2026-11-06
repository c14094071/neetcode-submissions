class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        graph = {}

        def dfs(source,target,visited):
            if(source==target):
                return True
            visited.add(source)
          
            for neighbor in graph[source]:
                if neighbor not in visited:
                    r = dfs(neighbor,target,visited)
                    if(r):
                        return True

            return False
        for u,v in edges:
            visited = set()
            if u in graph and v in graph and dfs(u,v,visited):
                return [u,v]

            if u not in graph:
                graph[u] = []
            graph[u].append(v)
            if v not in graph:
                graph[v] = []
            graph[v].append(u)
            
            