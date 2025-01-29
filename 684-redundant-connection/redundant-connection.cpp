class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector <int> parent(n + 2);
        for(int i = 0 ; i < n + 2 ; i++)
            parent[i] = i;
        function <int(int)> find = [&](int i) -> int{
            if(parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        };
        for(auto e : edges){
            int a = e[0] , b = e[1];
            int parA = find(a) , parB = find(b);
            if(parA == parB)
                return e;
            parent[parA] = parB;
        }
        return {};
    }
};