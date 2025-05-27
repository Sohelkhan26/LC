class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges)
            adj[e[0]].push_back({e[1] , e[2]});
        queue <vector<int>> q;
        for(int i = 0 ; i < n ; i++)
            q.push({i , 0 , 0});
        // set <vector<int>> vis;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(k + 1, vector<bool>(t, false)));
        int ans = -1;
        while(not q.empty()){
            auto it = q.front(); q.pop();
            int curr = it[0] , edge = it[1] , pathSum = it[2];
            if(edge == k){
                ans = max(ans , pathSum);
                continue;
            }
            for(auto &[nei , w] : adj[curr]){
                int newSum = pathSum + w;
                if(newSum < t and not vis[nei][edge + 1][newSum]){
                    vis[nei][edge + 1][newSum] = true;
                    q.push({nei , edge + 1 , newSum});
                }
            }
        }
        return ans;
    }
};