class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int sig) {
        int n = edges.size();
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &e : edges)
            adj[e[0]].push_back({e[1] , e[2]}),
            adj[e[1]].push_back({e[0] , e[2]});
        vector <int> ans;
        function<int(int,int,int)> DFS = [&](int curr , int par , int dist){
            int valid = dist % sig == 0;
            for(auto &[nei , d] : adj[curr])
                if(nei != par)
                    valid += DFS(nei , curr , dist + d);
            return valid;
        };
        for(int i = 0 ; i <= n ; i++){
            int prevNodes = 0 , res = 0 , valid = 0;
            for(auto &[node , dist] : adj[i]){
                valid = DFS(node , i , dist); // node-count in next subtree
                res += prevNodes * valid; // they form valid-pair with previous subtree
                prevNodes += valid; // these nodes will form pairs in future too.
            }
            ans.push_back(res);
        }
        return ans;
    }
};

/*
Awesome problem. Distance mean sum of weight along the path.
For every node c, for every pair [a , b] , c must be in between the path from a to b, and 
distance between c -> a and c -> b must be divisible by signaleSpeed. Find count of such pairs.
A Tree is given, for any node , it can have any number of children. To form a pair, A node must have at least 2 subtree. Nodes of one subtree can form a pair with nodes with another subtree.
So total pair = node-count-subtree1 * node-count-subtree2 . Note: only count nodes that have distance divisible by signalSpeed.
DFS function returns count-of-nodes satisfying the condition, nothing fancy.
The path from c to b and the path from c to a do not share any edges means node 'a' and 'b' can be in the same subtree.
*/
