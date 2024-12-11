class Solution {
public:
    vector<vector<bool>> vis;
    bool dfs(int i , int j , int parI , int parJ , vector<vector<char>> &grid){
        vis[i][j] = true;
        for(auto [di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
            int newi = i + di , newj = j + dj;
            if(min(newi , newj) >= 0 and newi < grid.size() and newj < grid[0].size() and grid[newi][newj] == grid[i][j] and not(newi == parI and newj == parJ))
                if(vis[newi][newj] or dfs(newi , newj , i , j , grid))
                    return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vis.resize(n , vector<bool> (m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(not vis[i][j]){
                    if(dfs(i , j , -1 , -1 , grid))
                        return true;
                }
            }
        }
        return false;
    }
};