class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int t = 0 ; t < n ; t++)
            for(int i = 0 ; i < n - 1 ; i++)
                for(int j = 0 ; j < n - 1 ; j++){
                    if(j > i){ // bottom left , decreasing order , i > i + 1 swap otherwise
                        if(grid[i + 1][j + 1] < grid[i][j])
                            swap(grid[i + 1][j + 1] , grid[i][j]);
                    } // top-right triangle, increasing order , i < i + 1 , swap otherwise
                    else if(grid[i + 1][j + 1] > grid[i][j])
                        swap(grid[i + 1][j + 1] , grid[i][j]);
                    }
        return grid;
    }
};