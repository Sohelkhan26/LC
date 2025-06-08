class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector <bool> vis(n) , temp(n);
        vector <int> ans;
        for(auto &it : edges)
            adj[it[0]].push_back(it[1]);
        bool canRemove = true;
        function<void(int)> dfs = [&](int curr){
            vis[curr] = true;
            for(int &nei : adj[curr])
                if(not vis[nei])
                    dfs(nei);
        };
        dfs(k);
        for(int i = 0 ; i < n ; i++){
            if(not vis[i]){ // external node
                for(int &nei : adj[i]){
                    if(vis[nei]){ // from external node, sus node is called
                        canRemove = false;
                        break;
                    }
                }
                if(not canRemove)
                    break;
            }
        }
        for (int i = 0; i < n; i++) {
            if(canRemove){
                if(!vis[i])
                    ans.push_back(i);  // keep only non-suspicious
            }else{
                ans.push_back(i);  // cannot canRemove, return all
            }
        }
        return ans;
    }
};