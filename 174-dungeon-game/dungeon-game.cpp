class Solution {
public:
    int n , m;
    int dp[201][201];
    int solve(int i , int j , vector<vector<int>> &grid){
        if(i >= n or j >= m)
            return INT_MAX;
        if(i == n - 1 and j == m - 1) // min health to enter (n-1,m-1)?
            return grid[i][j] < 0 ? abs(grid[i][j]) + 1 : 1; // if this cell decrease health we need at least this health + 1(to make back alive). If this cell increase health, we need 1 health
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i , j + 1 , grid);
        int down = solve(i + 1 , j , grid);
        int ans = min(right , down); // we will choose path that requires minimum health either right or down
// dp[i][j] tells us what should be our min health if we want to enter this cell (i,j). we should have enough health to survive this cell, and remaining path to (n - 1 , m - 1) which is saved in ans. If want to go to ans cell(right/down) we should have ans health. If grid[i][j] enough, we need to have 1 health entering (i,j) otherwise ans - grid[i][j] to live through the path starting from (i,j) -> (n-1,m-1)
        return dp[i][j] = (grid[i][j] >= ans ? 1 : ans - grid[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size() , m = dungeon[0].size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , dungeon); 
    }
};

/*
You are at (0,0) cell, want to go to (n - 1 , m - 1) cell with at least 1 health
each cell including source and destination have +/- values, add them to your health.
Return the minimum health you should have to reach (n - 1 , m - 1) cell

We ask what should be the min health if you want to enter n - 1 , m - 1
recursively 
*/