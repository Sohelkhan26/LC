class Solution {
public:
    typedef long long ll;
    vector<vector<int>> adj;
    pair<long long,int> dfs(int curr , int par , vector<int> &cost){
        vector <ll> childs;
        int ans = 0;
        for(int &nei : adj[curr]){
            if(nei == par) continue;
            auto childAns = dfs(nei , curr , cost);
            ans += childAns.second;
            childs.push_back(childAns.first);
        }
        if(childs.empty()) // leaf node
            return {cost[curr] , 0};
        long long maxChild = *max_element(childs.begin() , childs.end());
        for(auto &c : childs)
            if(c != maxChild)
                ans++;
        return {maxChild + cost[curr] , ans};
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        return dfs(0 , 0 , cost).second;
    }
};


/*
changing a root value, affects the whole subtree rooted at that node uniformly.
Changing root node is not optimal right?
For each root, ask it's child, left and right child path sum differ, we need one change right? let's say we make the smaller child bigger, then propagate this answer to up. 
But we have to minimize operations. How can we do that? above one only simulates the process.
And amazingly it passes. Some questions asks to minimize the result but there is no place to minimize. Of course changing each node to some constant value works. Maybe that's why it asks to minimize operations.
*/