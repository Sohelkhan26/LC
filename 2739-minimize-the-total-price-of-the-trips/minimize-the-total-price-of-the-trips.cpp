class Solution {
public: 
    vector<vector<int>> adj;
    vector<int> contrib;
 

    bool dfs(int curr , int par , int dest , vector<int> &price){ // DFS will return true along a path
        if(curr == dest){
            contrib[dest]++;
            return true;
        }
            
        for(int nei : adj[curr]){
            if(nei == par)
                continue;
            if(dfs(nei , curr , dest , price)){
                contrib[curr]++;
                return true;
            }
        }
        return false;
    }
    // {current node halved , current node not halved/skipped}
    pair<int,int> solve(int curr , int par , vector<int> &price){
        int take = (price[curr] / 2) * contrib[curr];
        int skip = price[curr] * contrib[curr];
        for(int nei : adj[curr]){
            if(nei == par)
                continue;
            auto child = solve(nei , curr , price);
            skip += min(child.first , child.second); // current node skipped, child can either be halve or skipped
            take += child.second; // But if current node is halved, child node must be skipped
        }
        return {take , skip};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        adj = vector<vector<int>> (n);
        contrib = vector<int> (n); 

        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]); 

        for(auto &t : trips){
            int start = t[0] , end = t[1];  
            dfs(start , start , end , price);
        }

        auto ans = solve(0 , 0 , price);
        return min(ans.first , ans.second);
    }
};

/*
Given a unrooted tree with n nodes. and n - 1 edges
each node has an price. You can choose some non adjacent nodes and halve the price. Better to choose all non-adjacent nodes and halve? Greedy don't work. Have to apply Dp.
for each trip[i] = {start , end} find minimal path 
and return sum of all trips

For a tree there is an unique path between any two nodes.
So, we can't minimize cost by choosing some other nodes. Have to reduce cost
choosing to halve a node or not.

All trips can be merged and each nodes contribution in the path of each trips can be calculated.
Since it's a unrooted tree, we can choose any node as root and apply DP. To use same memoization table, we need 2D DP, otherwise reset 1D Dp for each solve function call?

Dp will calculate maximum discount achievable for all nodes present in any trip.
*/