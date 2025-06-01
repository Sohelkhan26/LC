class Solution {
public:
    using pii = pair<long long, long long>;
    unordered_map<long long, vector<pii>> graph; // node -> list of (neighbor, weight)
    long long k;
    vector<vector<long long>> dp;
    long long solve(long long curr , bool hasPar , long long parent){ // returns max-weight achieveable of the subtree rooted at curr
        if(dp[curr][hasPar] != -1)
            return dp[curr][hasPar];
        vector<vector<long long>> cost;
        for(auto &[nei , w] : graph[curr]){
            if(nei == parent)continue;
            long long remove = solve(nei , false , curr); // remove this edge
            long long dontRemove = w + solve(nei , true , curr); // keep this edge
            cost.push_back({dontRemove - remove , nei , w});
        }
        sort(cost.rbegin() , cost.rend()); 
        long long keep = 0 , limit = k - hasPar , ans = 0; // if there is a parent , we can keep k - 1 edge
        for(auto &it : cost){
            long long delta = it[0] , nei = it[1] , w = it[2];
            if(delta > 0 and keep < limit) // delta > 0 means keeping (keep value) the edge gives us better answer.
                keep++ , ans += (w + solve(nei , true , curr));
            else ans += solve(nei , false , curr); // dont worry memoization reduces recalculation
        }
        return dp[curr][hasPar] = ans;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int _k) {
        k = _k;

        // Build the undirected graph
        for (auto& e : edges) {
            long long u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        long long n = graph.size();
        dp.resize(n , vector<long long> (2 , -1));

        return solve(0, false, -1); // Start from root node 0, no parent
    }
};

/*
After removal each node can at most k edge.
at most n - 1 edge. If there are no multi-edge between two nodes, there will be
one path among two nodes. But if there is multi-edge, some nodes may not be
connected. remove edge so that remaining edge-weight-sum maximised. Tried
greedy. But greedy won't work. consider A --> 4 --> B --> 7 --> C --> 4 --> D.
And k= 1. Greedy only has 7 remain. The optimal is having the AB, CD edges with
sum 8 remain
This is a hard problem. Solveable by DP.
Each node can have at most k edges. For each edge, we can either keep it or remove it. Take the best option.
But how to ensure each node as k edges? As we are using memoization, a clever way is to visit each nodes twice.
For each node calculate "keep - remove" difference for each edge connected to this node.
Out of these keep min(k , edgeCount) edges.
But how do we know if this node was previously connected with any other node or not ?
Keep a boolean value to determine that. If there was a parent we can keep at most k - 1 edge or if there was not parent keep 'k' edges.
*/