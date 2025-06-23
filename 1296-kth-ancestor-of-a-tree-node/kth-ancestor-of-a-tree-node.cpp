class TreeAncestor {
public:
    vector<vector<int>> up;
    int height;
    TreeAncestor(int n, vector<int>& parent) {
        height = ceil(log2(n));

        up = vector<vector<int>> (n , vector<int> (height + 1 , -1));

        for(int node = 0 ; node < n ; node++)
            up[node][0] = parent[node];

        for(int k = 1 ; k <= height ; k++)
            for(int node = 0 ; node < n ; node++)
                if(up[node][k - 1] != -1)
                    up[node][k] = up[ up[node][k - 1] ][k - 1];
            
    }
    
    int getKthAncestor(int node, int k) {
        for(int bit = 0 ; bit <= height and node != -1 ; bit++)
            if(k & (1 << bit))
                node = up[node][bit];
        
        return node;
    }
};
