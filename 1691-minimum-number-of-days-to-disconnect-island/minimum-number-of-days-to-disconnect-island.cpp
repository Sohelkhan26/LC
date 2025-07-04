class Solution {
public:
    int dir[5] = {1 , 0 , -1 , 0 , 1} , n , m;
    bool valid(int i , int j){
        return min(i , j) >= 0 and i < n and j < m;
    }
    void DFS(int i , int j , vector<vector<bool>> &vis , vector<vector<int>> &grid){
        vis[i][j] = true;
        for(int k = 0 ; k < 4 ; k++){
            int newI = i + dir[k] , newJ = j + dir[k + 1];
            if(valid(newI , newJ) and not vis[newI][newJ] and grid[newI][newJ])
                DFS(newI , newJ , vis , grid);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        auto count = [&](){
            vector<vector<bool>> vis(n , vector<bool> (m));
            int island = 0;
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < m ; j++)
                    if(not vis[i][j] and grid[i][j])
                        DFS(i , j , vis , grid) , island++;
            return island;
        };
        int cnt = count();
        cout << cnt << endl;
        if(cnt == 0 or cnt > 1)
            return 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    cnt = count();
                    if(cnt > 1 or cnt == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};