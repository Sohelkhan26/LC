class Solution {
public:
    vector <int> parent;
    int find(int i){
        if(parent[i] != i)
            return parent[i] = find(parent[i]);
        return parent[i];
    }
    void Union(int i , int j){
        i = find(i) , j = find(j);
        parent[i] = j;
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size() , component = n;
        parent.resize(n);
        iota(parent.begin() , parent.end() , 0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    if(find(i) != find(j))
                        Union(i , j) , component--;
                }
            }
        }
        return component;
    }
};