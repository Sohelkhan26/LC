class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        queue <pair<int,int>> q;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == 1)
                    q.push({i , j});
        if(q.size() == n * m) // no land cell
            return -1;
        int dist = 0;
        int dir[] = {1 , 0 , -1 , 0 , 1};
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [i , j] = q.front(); q.pop();
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + dir[k] , newJ = j + dir[k + 1];
                    if(min(newI , newJ) >= 0 and newI < n and newJ < m and grid[newI][newJ] == 0)
                        q.push({newI , newJ}) , grid[newI][newJ] = 1;
                }
            }
            dist++;
        }
        return dist - 1;
    }
};