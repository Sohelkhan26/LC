class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges)
            adj[e[0]].push_back({e[1] , e[2]});
        queue <vector<int>> q;
        for(int i = 0 ; i < n ; i++)
            q.push({i , 0 , 0});
        set <vector<int>> vis;
        int ans = -1;
        while(not q.empty()){
            auto it = q.front(); q.pop();
            if(it[1] == k){
                ans = max(ans , it[2]);
                continue;
            }
            for(auto &[nei , w] : adj[it[0]]){
                vector<int> newIt = {nei , it[1] + 1 , it[2] + w};
                if(it[2] + w < t and not vis.contains({newIt})){
                    q.push(newIt);
                    vis.insert(newIt);
                }
            }
        }
        return ans;
    }
};