class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<int> row(n) , col(m);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                row[i] += grid[i][j],
                col[j] += grid[i][j];
        long long ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                    ans += grid[i][j] * (row[i] - 1) * (col[j] - 1);
        return ans;
    }
};