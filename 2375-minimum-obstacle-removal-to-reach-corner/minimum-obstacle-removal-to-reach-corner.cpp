class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n , vector<int> (m , INT_MAX));
        vector<vector<bool>> vis(n , vector<bool> (m));
        deque <pair<int,int>> d;
        d.push_front({0 , 0});
        dp[0][0] = grid[0][0];
        vis[0][0] = true;
        while(not d.empty()){
            auto [x , y] = d.front(); d.pop_front();
            for(auto [dx , dy] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                int newX = x + dx , newY = y + dy;
                if(min(newX , newY) >= 0 and newX < n and newY < m and vis[newX][newY] == false){
                    dp[newX][newY] = dp[x][y] + grid[x][y];
                    if(grid[newX][newY] == 1)
                        d.push_back({newX , newY});
                    else d.push_front({newX , newY});
                    vis[newX][newY] = true;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};