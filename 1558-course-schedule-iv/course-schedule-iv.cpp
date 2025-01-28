class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector <int> adj[101];
        for(auto it : pre)
            adj[it[0]].push_back(it[1]);
        vector <bool> vis(n) , ans;
        function<bool(int,int)> dfs = [&](int i , int target) -> bool{
            vis[i] = true;
            if(i == target)
                return true;
            for(int nei : adj[i]){
                if(not vis[nei]){
                    if(dfs(nei , target))
                        return true;
                }
            }
            return false;
        };
        for(auto it : q){
            for(int i = 0 ; i < n ; i++)
                vis[i] = false;
            ans.push_back(dfs(it[0] , it[1]));
        }
        return ans;
    }
};