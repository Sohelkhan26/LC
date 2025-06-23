class TreeAncestor {
public:
    vector<vector<int>> up;  
    int height = 0;

    TreeAncestor(int n, vector<int>& parent) {
        height = ceil(log2(n));

        up = vector<vector<int>>(n, vector<int>(height + 1, -1));

        for (int node = 0; node < n; node++) {
            up[node][0] = parent[node];
        }

        for (int k = 1; k < height; k++) {
            for (int node = 0; node < n; node++) {
                int mid = up[node][k - 1];
                if (mid != -1)
                    up[node][k] = up[mid][k - 1];
            }
        }

    }

    int getKthAncestor(int node, int k) {
        for (int bit = 0; bit <= height && node != -1; bit++) {
            if (k & (1 << bit)) {
                node = up[node][bit];
            }
        }
        return node;
    }
};


/*
up[node][k] is the 2ᵏ-th ancestor of node
up[node][k - 1] is the 2ᵏ⁻¹-th ancestor of node
up[ up[node][k - 1] ][k - 1] means:

Start at node, go up 2ᵏ⁻¹ steps, then from that node, go up another 2ᵏ⁻¹ steps.
You reach 2ᵏ⁻¹ + 2ᵏ⁻¹ = 2 * 2 ^ (k - 1) = 2 ^ (k - 1 + 1) = 2ᵏ-th ancestor of node

*/