class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , fresh = 0 , time = -1;
        queue <pair<int,int>> q;
        for(int i = 0 ; i < n ; i++)   
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2)
                    q.push({i , j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [i , j] = q.front(); q.pop();
                for(auto [di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                    int newi = i + di , newj = j + dj;
                    if(min(newi , newj) >= 0 and  newi < n and newj < m and grid[newi][newj] == 1){
                        fresh--;
                        q.push({newi , newj});
                        grid[newi][newj] = 2;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time == -1 ? 0 : time;
    }
};

/*
It's a good problem. Multisource BFS problem. There could be multiple rotten oranges. Though the problem description doesn't explicitly contains this info. If the time is not updated then the BFS didn't run for once so the answer is 0. If there are still some fresh oranges it means that there exists a fresh orange that isn't four directionally connected to the current or future rotten oranges and should return -1.
*/