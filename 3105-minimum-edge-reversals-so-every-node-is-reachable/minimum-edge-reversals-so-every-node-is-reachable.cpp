class Solution {
public:
    vector<vector<int>> adj;
    int dfs1(int curr , int par){
        int ans = 0;
        for(int &nei : adj[curr]){
            if(abs(nei) == par)
                continue;
            ans += (nei < 0) + dfs1(abs(nei) , curr);
        }
        return ans;
    }
    void dfs2(int curr , int par , int reversal , vector<int> &ans){
        ans[curr] = reversal;
        for(int &nei : adj[curr]){
            if(abs(nei) == par)
                continue;
            dfs2(abs(nei) , curr , reversal + (nei < 0 ? -1 : 1) , ans);
        } 
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>> (n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(-e[0]);
        vector<int> ans(n);
        ans[0] = dfs1(0 , -1);
        dfs2(0 , -1 , ans[0] , ans);
        return ans;
    }
};

/*
If destination node is negative, we need a reverse edge.
Caculate the answer for any node we did for 0

Now run the second DFS from that node
For every neighbor, think of that node as root:
1. If we go to positive neighbor(original edge)
we have to reverse that edge to go back to parent, so count + 1
2. If we go to negative neighbor(reverse edge has to be used)
we don't have reverse that edge to go back to parent(there was a original edge), so count - 1
*/