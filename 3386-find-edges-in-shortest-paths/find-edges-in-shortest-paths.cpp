class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> dijkstra(int src){
        vector <int> dist(adj.size() , INT_MAX);
        dist[src] = 0;
        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<> > pq;
        pq.push({0  , src});
        while(not pq.empty()){
            auto [d , curr] = pq.top(); pq.pop();
            if(dist[curr] < d)
                continue;
            for(auto &[nei , w] : adj[curr]){
                if(d + w < dist[nei]){
                    dist[nei] = d + w;
                    pq.push({d + w , nei});
                }
            } 
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &e : edges)
            adj[e[0]].push_back({e[1] , e[2]}),
            adj[e[1]].push_back({e[0] , e[2]});
        vector <int> fromStart = dijkstra(0) , fromEnd = dijkstra(n - 1);
        int m = edges.size();
        vector<bool> ans(m);
        if(fromStart[n - 1] == INT_MAX)
            return ans;
        for(int i = 0 ; i < m ; i++){
            int from = edges[i][0] , to = edges[i][1] , w = edges[i][2];
            if(0ll + fromStart[from] + w + fromEnd[to] == fromStart[n -1]
            or 0ll + fromStart[to] + w + fromEnd[from] == fromStart[n -1])
                ans[i] = true;
        }
        return ans;
    }
};