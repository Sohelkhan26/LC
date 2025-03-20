class Solution {
public:
    vector <int> parent , rank;
    int Find(int x){
        if(x != parent[x])
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Union(int x , int y){
        x = Find(x) , y = Find(y);
        if(x != y){
            if(rank[x] < rank[y]){
                parent[x] = y;
                rank[y] += rank[x];
            }else{
                parent[y] = x;
                rank[x] += rank[y];
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin() , parent.end() , 0);
        vector <int> ans;
        for(auto it : edges)
            Union(it[0] , it[1]);
        unordered_map <int,int> leader;
        for(auto e : edges){
            int root = Find(e[0]) , w = e[2];
            if(leader.find(root) == leader.end())
                leader[root] = w;
            else leader[root] &= w;
        }
        for(auto q : query){
            int root1 = Find(q[0]) , root2 = Find(q[1]);
            if(root1 != root2)
                ans.push_back(-1);
            else ans.push_back(leader[root1]);
        }
        return ans;
    }
};

/*
At first I thought, we should find every possible path and find the path with least bitwise AND.
In bitwise AND order doesn't matter, if a bit is unset , then whatever the next numbers be, it will be always unset. And AND(a , b , c) <= min(a , b , c).
So, it is obvious that it's profitable to include all the edges between two nodes. It sure will decrease or at least be same. 
For every component, make some random node that components leader, and Bitwise AND every edge connected to this component.
Union find is a brilliant approach. 
*/