class Solution {
public:
    int ans = 0;
    vector<vector<int>> adj;
    long long dfs(int curr , int par , vector<int> &price){
        long long maxCost = 0;
        vector <long long> child;
        for(int nei : adj[curr]){
            if(nei == par)
                continue;
            long long t = dfs(nei , curr , price);
            maxCost = max(maxCost , t);
            child.push_back(t);
        }
        for(long long &i : child)
            if(i != maxCost)
                ans++;
        return 0ll + price[curr] + maxCost;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        dfs(0 , 0 , cost);
        return ans;
    }
};


/*
changing a root value, affects the whole subtree rooted at that node uniformly.
Changing root node is not optimal right?
For each root, ask it's child, left and right child path sum differ, we need one change right? let's say we make the smaller child bigger, then propagate this answer to up. 
But we have to minimize operations. How can we do that? above one only simulates
*/