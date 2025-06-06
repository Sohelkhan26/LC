class Solution {
public: 
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int Min = INT_MAX;
                if(i == 0 and j == 0)continue;
                if(i)
                    Min = min(Min , grid[i - 1][j]); // min on left side. acts as prefix min of left side.
                if(j)
                    Min = min(Min , grid[i][j - 1]); // min on upper side.
                ans = max(ans , grid[i][j] - Min);
                grid[i][j] = min(grid[i][j] , Min);
            }
        }
        return ans;
    }
};

/*
We can start and stop anywhere. Can go to bottom/right only (may not be adjacent).
score = grid[to] - grid[from]
return max score.
Screaming i'm DP? 
Wrong observation and decision. 5 -> 7 -> 14 score = 7 - 5 + 14 - 7 = 14 - 5
10 -> 13 -> 18 -> 92 = 13 - 10 + 18 - 13 + 92 - 18 = 92 - 10 
Simple but elegant observation. Path don't matter only starting and ending matter. 
Cause of the way to calculate score. Keep track of min element at left and top.
*/