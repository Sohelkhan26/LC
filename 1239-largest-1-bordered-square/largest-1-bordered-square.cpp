class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        vector <vector<int>> right(n + 1 , vector <int> (m + 1)) , down;
        down = right;
        for(int i = n - 1 ; i >= 0 ; i--)
            for(int j = m - 1 ; j >= 0 ; j--)
                if(grid[i][j]){
                    right[i][j] = 1 + right[i][j + 1];
                    down[i][j] = 1 + down[i + 1][j];
                }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int maxSize = min(right[i][j] , down[i][j]);
                for(int side = maxSize ; side > 0 ; side--)
                    if(right[i + side - 1][j] >= side and down[i][j + side - 1] >= side){
                        ans = max(ans , side * side);
                        break;
                    }
            }
        }
        return ans;
    }
};