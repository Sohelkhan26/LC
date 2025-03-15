class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size() , ans = 0;
        vector <int> rowMax(n) , colMax(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                rowMax[i] = max(rowMax[i] , grid[i][j]);
                colMax[j] = max(colMax[j] , grid[i][j]);
            }
        }

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                ans += (min(rowMax[i] , colMax[j]) - grid[i][j]);
        return ans;
    }
};

/*
Normal implementation problem, but a good problem.
No complex thinking. Any building can be increased, not more than any building on either it's side.
So, it can be increased either to max of each row or column, whichever is minimum.
i -> row , j -> col
*/