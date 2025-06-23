class Solution {
public:
    vector<int> level;
    vector<vector<int>> adj , up;
    int n , height , mod = 1e9 + 7;
    void dfs(int curr , int par , int depth){
        level[curr] = depth;
        up[curr][0] = par;
        for(int &nei : adj[curr])
            if(nei != par)
                dfs(nei , curr , depth + 1);
    }
    int power(int n , int p){
        if(p == 0)
            return 1;
        int ans = power(n , p / 2);
        ans = (1ll * ans * ans) % mod;
        if(p % 2)
            ans = (ans * n) % mod;
        return ans;
    }

    void binaryLifting(){
        for(int k = 1 ; k <= height ; k++)
            for(int node = 1 ; node <= n ; node++){
                int par = up[node][k - 1];
                if(par != -1)
                    up[node][k] = up[par][k - 1];
            }
    }

    int findLCA(int a , int b){
        if(level[a] < level[b])
            swap(a , b);
        
        int diff = level[a] - level[b];
        for (int i = height; i >= 0; --i)
            if ((diff >> i) & 1)
                a = up[a][i];

        if(a == b)
            return a;
        
        for(int jump = height ; jump >= 0 ; jump--)
            if(up[a][jump] != up[b][jump] and up[a][jump] != -1 and up[b][jump] != -1)
                a = up[a][jump] , b = up[b][jump];
        
        return up[a][0];
    } 

    int findDist(int a , int b){
        int lca = findLCA(a , b);
        return level[a] - level[lca] + level[b] - level[lca];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        height = ceil(log2(n));

        adj = vector<vector<int>> (n + 1);
        up = vector<vector<int>> (n + 1 , vector<int> (height + 1 , -1));
        level = vector<int> (n + 1);

        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);

        dfs(1 , -1 , 0);
        binaryLifting();

        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0 ; i < m ; i++){
            int a = queries[i][0] , b = queries[i][1];
            int path = findDist(a , b);
            if(path == 0)
                continue;
            ans[i] = power(2 , path - 1);
        }
        return ans;
    }
};