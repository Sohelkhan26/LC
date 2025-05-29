class Solution {
public:
    int dp[301][301][16];
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() , mod = 1e9 + 7;
        memset(dp , -1 , sizeof(dp));
        function<int(int,int,int)> dfs = [&](int i , int j , int Xor) -> int{
            if(i >= n or j >= m)
                return 0;
            Xor ^= grid[i][j];
            if(i == n - 1 and j == m - 1)
                return (int)Xor == k;
            if(dp[i][j][Xor] != -1)
                return dp[i][j][Xor];
            int right = dfs(i , j + 1 , Xor) , down = dfs(i + 1 , j , Xor);
            return dp[i][j][Xor] = (right + down) % mod;
        };
        return dfs(0 , 0 , 0) % mod;
    }
};