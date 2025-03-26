class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector <bool> vis(n);
        vector<vector<int>> adj(n);
        int comp = 0 , len = connections.size();
        function<void(int)> dfs = [&](int i){
            vis[i] = true;
            for(int j : adj[i])
                if(not vis[j])
                    dfs(j);
        };
        for(auto c : connections)
            adj[c[0]].push_back(c[1]) , adj[c[1]].push_back(c[0]);
        for(int i = 0 ; i < n ; i++)
            if(not vis[i])
                dfs(i) , comp++;
        return len >= n - 1 ? comp - 1 : -1;
    }
};