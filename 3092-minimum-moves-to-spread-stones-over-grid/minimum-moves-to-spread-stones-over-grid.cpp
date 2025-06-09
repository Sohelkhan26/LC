class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int need = 0 , ans = 1e5;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                need += (grid[i][j] == 0);
        if(need == 0) // base case all cells have 1 stone
            return 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(grid[i][j] != 0) 
                    continue;
                for(int ni = 0 ; ni < 3 ; ni++){
                    for(int nj = 0 ; nj < 3 ; nj++){
                        if(grid[ni][nj] > 1){
                            grid[i][j]++;
                            grid[ni][nj]--;
                            ans = min(ans , abs(ni - i) + abs(nj - j) + minimumMoves(grid));
                            grid[i][j]--; // dont forget to undo changes.
                            grid[ni][nj]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*
only one stone can be moved to adjacent cell.
This made things complicated. First thought of DP with visited array, but that  will be complicated.
any cell can be visited multiple times for sake of transferring stones to another cell.
This solution is taken from another person. 
If a cell has 0 stone, take a stone from a cell with > 1 stones, and solve the rest.
Awesome backtracking problem.
*/