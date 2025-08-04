class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        adj = collections.defaultdict(list)
        for u , v , count in edges:
            adj[u].append((v , count + 1))
            adj[v].append((u , count + 1))
        q = [(maxMoves , 0 , 0)] #
        vis = {0 : maxMoves}
        while q :
            nextLevel = []
            for moves , curr , par in q : 
                if curr in vis and vis[curr] > moves: 
                    continue
                for nei , cost in adj[curr]:
                    if cost > moves or nei == par:
                        continue
                    if nei not in vis or vis[nei] < moves - cost:
                        nextLevel.append((moves - cost , nei , curr))
                        vis[nei] = moves - cost
            q = nextLevel

        ans = len(vis)
        intermediate = sum(min(vis.get(u , 0) + vis.get(v , 0) , cost) for u , v , cost in edges)
        return intermediate + len(vis)