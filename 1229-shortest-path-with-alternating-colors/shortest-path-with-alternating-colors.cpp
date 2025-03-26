class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int red = 1 , blue = 2;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : redEdges)
            adj[it[0]].push_back({it[1] , red});
        for(auto it : blueEdges)
            adj[it[0]].push_back({it[1] , blue});
        vector <int> dist(n , -1);
        queue <pair<int,int>> q;
        q.push({0 , -1}); // so that, next edge can be anything red or blue.
        int d = 0; // distance from 0
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [node , color] = q.front(); q.pop();
                if(dist[node] == -1) // Don't update if it was previously updated.
                    dist[node] = d;
                for(auto &[nei , neiC] : adj[node]){
                    if(color != neiC and nei != -1){
                        q.push({nei , neiC});
                        nei = -1;
                    }
                }
            }
            d++;
        }
        return dist;
    }
};

/*
Quite a tricky problem.
Trick part is that we can visit a node twice, once via a red edge and once via blue edge. So mainaining trivial visited array won't suffice.
We can keep track of visited state by directly modifying the adjacency list or by a set of pairs.
And the rest is basic BFS.
*/