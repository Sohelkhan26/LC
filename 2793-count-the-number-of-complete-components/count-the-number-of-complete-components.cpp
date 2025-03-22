class Solution {
public:
    vector <int> adj[51];
    vector <bool> vis;
    pair<int,int> dfs(int i){
        vis[i] = true;
        pair <int,int> nodeEdge = {1 , 0}; // {node , edge}
        nodeEdge.second += adj[i].size();
        for(int j : adj[i])
            if(not vis[j]){
                auto a = dfs(j);
                nodeEdge.first += a.first , nodeEdge.second += a.second;
            }
        return nodeEdge;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vis.resize(n);
        for(auto e : edges)
            adj[e[0]].push_back(e[1]) , adj[e[1]].push_back(e[0]);
        for(int i = 0 ; i < n ; i++){
            if(not vis[i]){
                auto [node , edge] = dfs(i);
                if(node * (node - 1) * 1ll == edge)
                    ans++;
            }
        }
        return ans;
    }
};

/*
For a component to be complete it must have n * (n - 1) / 2 unique edges (equal to the number of pairs of nodes in the graph). Since the given graph is undirected adjacency list counts each edge twice (once from each endpoint).
So, run DFS on each component and calculate node and edge count.
if node * (node - 1) == edge then it's a complete component.
*/