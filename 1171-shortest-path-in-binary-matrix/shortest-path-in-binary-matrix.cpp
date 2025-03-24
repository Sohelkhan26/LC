class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])return -1;
        queue <pair<int,int>> q;
        q.push({0 , 0});
        int path = 0 , n = grid.size();
        while(not q.empty()){
            int len = q.size();
            path++;
            while(len--){
                auto [i , j] = q.front(); q.pop();
                if(i == n - 1 and j == n - 1)
                    return path;
                grid[i][j] = 1;
                for(int x = -1 ; x <= 1 ; x++)
                    for(int y = -1 ; y <= 1 ; y++){
                        if(x == 0 and y == 0)continue;
                        int newI = i + x , newJ = j + y;
                        if(min(newI , newJ) >= 0 and max(newI , newJ) < n and grid[newI][newJ] == 0){
                            q.push({newI , newJ});
                            grid[newI][newJ] = 1;
                        }
                    }
            }
        }
        return -1;
    }
};